#include <stdio.h>
#include <string.h>
#include <riscv_vector.h>

#define VLEN 128

// A[m][n] * B[n] = C[m] 
void mvp(float *A, float *B, float *C, int m, int n) {
    for(int i=0; i<m; i++)
	for (int j=0; j<n; j++){
	    C[i] += A[i*m+j] * B[j];
	}
}

void mvp_vv(float *A, float *B, float *C, int m, int n){
    size_t vlmax = __riscv_vsetvlmax_e32m1();
    for(int i=0; i<m; i++)
        for (int j=0; j<n; j++){
	    float *ptr_a = A+(i*n);
	    float *ptr_b = B;
	    int k = n;
      vfloat32m1_t vec_s = __riscv_vfmv_v_f_f32m1(0, vlmax);
      vfloat32m1_t vec_zero = __riscv_vfmv_v_f_f32m1(0, vlmax);
      for (size_t vl; k > 0; k -= vl, ptr_a += vl, ptr_b += vl) {
        vl = __riscv_vsetvl_e32m1(k);

        vfloat32m1_t vec_a = __riscv_vle32_v_f32m1(ptr_a, vl);
        vfloat32m1_t vec_b = __riscv_vle32_v_f32m1(ptr_b, vl);

        vec_s = __riscv_vfmacc_vv_f32m1(vec_s, vec_a, vec_b, vl);
      }

      vfloat32m1_t vec_sum;
      vec_sum = __riscv_vfredusum_vs_f32m1_f32m1(vec_s, vec_zero, vlmax);
      float sum = __riscv_vfmv_f_s_f32m1_f32(vec_sum);
      C[i] = sum;	    
        }    
}

void mvp_instr(float *A, float *B, float *C, int m, int n);

int main(){
    float a[VLEN*VLEN], b[VLEN], c[VLEN];
    int i=0;
    for (i=0;i<VLEN*VLEN;i++)
	a[i] = 1.0;
    for(i=0;i<VLEN;i++)
	b[i] = 2.0;

    memset(c, 0, VLEN*sizeof(float));
    mvp(a,b,c, VLEN, VLEN);
    printf("%d \n", *c);

    memset(c, 0, VLEN*sizeof(float));
    //mvp_vv(a,b,c, VLEN, VLEN);
    //printf("%f \n", *c);

    memset(c, 0, VLEN*sizeof(float));
    mvp_instr(a,b,c, VLEN, VLEN);
    //printf("%f \n", c[0]);

    __riscv_mvp(a, b, c);
    printf("completed.\n");
    fflush(stdout);
    return 0;
}
