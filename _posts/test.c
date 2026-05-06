#include <fenv.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10000
#define DEN 10000

#define F16
// #define F32

struct Result { float value; float error; };

char* mode_string(int mode) {
    switch (mode) {
        case FE_DOWNWARD:
            return "FE_DOWNWARD";
        case FE_UPWARD:
            return "FE_UPWARD";
        case FE_TOWARDZERO:
            return "FE_TOWARDZERO";
        case FE_TONEAREST:
            return "FE_TONEAREST";
        default:
            return "None";
    }
}

void result_print(struct Result* res, int mode) {
};

#ifdef F16
void result_populate(double res_actual, float* a, float* b, _Float16* c, struct Result* res, int n, int mode) {
#else
void result_populate(double res_actual, float* a, float* b, float* c, struct Result* res, int n, int mode) {
#endif
    float res_val = 0;

    fesetround(mode);

    for (int i=0; i<n; i++) {
        c[i] = a[i]*b[i];
        res_val += c[i]; 
    }

    float error = fabs(res_actual - res_val);

    res->value = res_val;
    res->error = error;
}

void init(struct Result* res, float* a, float* b, double* c, int n, int seed) {
    srand(seed);
    for (int i=0; i<n; i++) a[i] = (float)rand() / (float)RAND_MAX;  // NOLINT
    for (int i=0; i<n; i++) b[i] = (float)rand() / (float)RAND_MAX;  // NOLINT

    double res_val = 0;
    for (int i=0; i<N; i++) {
        c[i] = (double)a[i] * (double)b[i];
        res_val += c[i];
    }

    res->value = res_val;
    res->error = 0;
}

int main(int argc, char* argv[]) {

    float* a = (float*)malloc(N * sizeof(float));
    float* b = (float*)malloc(N * sizeof(float));
    double* c = (double*)calloc(N,  sizeof(double));

    struct Result* res = (struct Result*)malloc(sizeof(struct Result));
    init(res, a, b, c, N, 42);

    int modes[4] = { FE_TOWARDZERO, FE_DOWNWARD, FE_UPWARD, FE_TONEAREST };

    for (int i=0; i<4; i++) {
#ifdef F16
        _Float16* c_inner = (_Float16*)calloc(N,  sizeof(_Float16));
#else
        float* c_inner = (float*)calloc(N,  sizeof(float));
#endif
        struct Result* res_inner = (struct Result*)malloc(sizeof(struct Result));

        result_populate(res->value, a, b, c_inner, res_inner, N, modes[i]);
        printf("Mode: %s, Value: %e, Error: %e\n", mode_string(modes[i]), res_inner->value, res_inner->error);

        free(c_inner); free(res_inner);
    }

    free(a); free(b); free(c); free(res);

    return 0;
}
