#include <stdio.h>
#include <string.h>

#define VLEN 128

void mvp(float *A, float *B, float *C, int m, int n) {
    for(int i=0; i<m; i++)
	for (int j=0; j<n; j++){
	    C[i] += A[j] * B[i*m+j];
	}
}

void mvp_instr(float *A, float *B, float *C, int m, int n);

int main(){
    float a[VLEN], b[VLEN*VLEN], c[VLEN];
    int i=0;
    for (i=0;i<VLEN;i++)
	a[i] = 1.0;
    for(i=0;i<VLEN*VLEN;i++)
	b[i] = 2.0;

    mvp(a,b,c, VLEN, VLEN);
    printf("%f \n", *c);

    memset(c, 0, VLEN*sizeof(float));
    //mvp_instr(a,b,c, VLEN, VLEN);
    printf("%f \n", *c);
    fflush(stdout);
    return 0;
}
