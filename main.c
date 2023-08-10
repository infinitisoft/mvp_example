#include <stdio.h>
#include <string.h>
//#include <riscv_vector.h>

#define VLEN 128

// A[m][n] * B[n] = C[m] 
void mvp(float *A, float *B, float *C, int m, int n) {
    for(int i=0; i<m; i++)
	for (int j=0; j<n; j++){
	    C[i] += A[i*m+j] * B[j];
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
    printf("%f \n", *c);

    memset(c, 0, VLEN*sizeof(float));
    //mvp_vv(a,b,c, VLEN, VLEN);
    //printf("%f \n", *c);

    memset(c, 0, VLEN*sizeof(float));
    mvp_instr(a,b,c, VLEN, VLEN);
    //printf("%f \n", c[0]);

    //__riscv_mvp(a, b, c);
    printf("completed.\n");
    fflush(stdout);
    return 0;
}
