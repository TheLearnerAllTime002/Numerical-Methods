#include <stdio.h>
#include <math.h>

#define TOL 0.0001
#define MAX_ITER 100

double f(double x) { return x*x*x - 8*x - 4; }
double df(double x) { return 3*x*x - 8; }

double newton_raphson(double x0) {
    double x = x0;
    for (int i = 0; i < MAX_ITER; i++) {
        double fx = f(x), dfx = df(x);
        if (fabs(fx) < TOL) return x;
        if (dfx == 0) return NAN;
        x = x - fx/dfx;
    }
    return NAN;
}

int main() {
    double x0;
    printf("Enter initial guess: ");
    while (scanf("%lf", &x0) == 1) {
        double root = newton_raphson(x0);
        if (!isnan(root)) {
            printf("Root: %.4f\n", root);
            break;
        }
        printf("No convergence. Try another guess: ");
    }
    return 0;
}