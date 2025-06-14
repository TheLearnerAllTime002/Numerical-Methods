#include <stdio.h>
#include <math.h>

#define TOL 0.0001
#define STEP 0.1
#define MAX_ITER 100

double f(double x) { return x*x - 4; }

double regula_falsi(double a, double b) {
    double fa = f(a), fb = f(b), c, fc;
    for (int i = 0; i < MAX_ITER; i++) {
        c = (a*fb - b*fa)/(fb - fa);
        if (fabs(fc = f(c)) < TOL) return c;
        (fa*fc < 0) ? (b = c, fb = fc) : (a = c, fa = fc);
    }
    return NAN;
}

void find_roots() {
    double a, b;
    printf("Enter range [a b]: ");
    scanf("%lf %lf", &a, &b);
    
    int found = 0;
    for (double x = a; x < b; x += STEP) {
        if (f(x)*f(x+STEP) > 0) continue;
        double root = regula_falsi(x, x+STEP);
        if (!isnan(root)) { printf("Root: %.4f\n", root); found = 1; }
    }
    
    if (!found) {
        printf("No roots in [%.1f,%.1f]. ", a, b);
        find_roots(); // Recursively prompt again
    }
}

int main() {
    find_roots();
    return 0;
}