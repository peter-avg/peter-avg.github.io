#include <fenv.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10
#define DEN 1000

int main(int argc, char* argv[]) {

    float* a = (float*)malloc(N * sizeof(float));
    float* b = (float*)malloc(N * sizeof(float));

    double* c = (double*)calloc(N,  sizeof(double));

    float* c_zero = (float*)calloc(N,  sizeof(float));
    float* c_nearest = (float*)calloc(N,  sizeof(float));
    float* c_up = (float*)calloc(N,  sizeof(float));
    float* c_down = (float*)calloc(N,  sizeof(float));

    srand(42);
    for (int i=0; i<N; i++) a[i] = 1.0f / (float)((rand() % (DEN-1)) + 1);  // NOLINT
    for (int i=0; i<N; i++) b[i] = 1.0f / (float)((rand() % (DEN-1)) + 1);  // NOLINT

    double res = 0;
    for (int i=0; i<N; i++) {
        c[i] = (double)a[i] * (double)b[i];
        res += c[i];
    }
    printf("Actual: %e\n", res);

    float res_zero = 0;
    fesetround(FE_TOWARDZERO);
    for (int i=0; i<N; i++) {
        c_zero[i] = a[i]*b[i];
        res_zero += c_zero[i]; 
    }
    float error_zero = fabs(res - res_zero);
    printf("Round towards zero error: %e\n", error_zero);

    float res_down = 0;
    fesetround(FE_DOWNWARD);
    for (int i=0; i<N; i++) {
        c_down[i] = a[i]*b[i];
        res_down += c_down[i]; 
    }
    float error_down = fabs(res - res_down);
    printf("Round downward error: %e\n", error_down);

    float res_up = 0;
    fesetround(FE_UPWARD);
    for (int i=0; i<N; i++) {
        c_up[i] = a[i]*b[i];
        res_up += c_up[i]; 
    }
    float error_up   = fabs(res - res_up);
    printf("Round upward error: %e\n", error_up);

    float res_nearest = 0;
    fesetround(FE_TONEAREST);
    for (int i=0; i<N; i++) {
        c_nearest[i] = a[i]*b[i];
        res_nearest += c_nearest[i]; 
    }
    float error_nearest = fabs(res - res_nearest);
    printf("Round to nearest error: %e\n", error_nearest);

    free(a); free(b); free(c); free(c_zero); free(c_nearest); free(c_up); free(c_down);

    return 0;
}
