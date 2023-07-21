#include <stdio.h>
#include <string.h>

void mvp(float *A, float *B, float *C, int m, int n) {
    for(int i=0; i<m; i++)
	for (int j=0; j<n; j++){
	    C[i] += A[j] * B[i*m+j];
	}
}

void mvp_instr(float *A, float *B, float *C, int m, int n);

int main(){
    float a[128], b[128*128], c[128];
    int i=0;
    for (i=0;i<128;i++)
	a[i] = 1.0;
    for(i=0;i<128*128;i++)
	b[i] = 2.0;

    mvp(a,b,c, 128, 128);
    printf("%f \n", *c);

    memset(c, 0, 128*sizeof(float));
    mvp_instr(a,b,c, 128, 128);
    printf("%f \n", *c);
    return 0;
}
