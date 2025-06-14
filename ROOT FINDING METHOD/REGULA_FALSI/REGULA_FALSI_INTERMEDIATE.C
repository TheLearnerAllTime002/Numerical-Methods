#include <stdio.h>
#include <math.h>

#define MAX_ITER 100

double f(double x) { return x*x*x - 3*x - 5 ; }  // Function to find roots for

void regula_falsi(double a, double b, double tol) {
    double fa = f(a), fb = f(b), c, fc;
    int iter = 0;
    
    printf("\nIteration Table for [%.2f, %.2f]:\n", a, b);
    printf("Iter\t a\t\t b\t\t c\t\t f(c)\n");
    printf("------------------------------------------------\n");
    
    do {
        iter++;
        c = (a*fb - b*fa)/(fb - fa);
        fc = f(c);
        
        printf("%d\t%.6f\t%.6f\t%.6f\t%.6f\n", iter, a, b, c, fc);
        
        if (fa*fc < 0) { b = c; fb = fc; }
        else { a = c; fa = fc; }
        
        if (iter >= MAX_ITER) {
            printf("Max iterations reached!\n");
            break;
        }
    } while (fabs(fc) > tol);
    
    printf("------------------------------------------------\n");
    printf("Final root: %.6f (after %d iterations)\n\n", c, iter);
}

void find_roots(double start, double end, double step, double tol) {
    int found = 0;
    
    for (double x = start; x < end; x += step) {
        if (f(x)*f(x+step) > 0) continue;
        
        regula_falsi(x, x+step, tol);
        found = 1;
    }
    
    if (!found) {
        printf("No roots found in [%.2f, %.2f] with step %.2f\n", start, end, step);
        printf("Enter new parameters (start end step tol): ");
        scanf("%lf %lf %lf %lf", &start, &end, &step, &tol);
        find_roots(start, end, step, tol);
    }
}

int main() {
    double start, end, step, tol;
    
    printf("Regula Falsi Method\n");
    printf("Enter parameters (start end step tolerance): ");
    scanf("%lf %lf %lf %lf", &start, &end, &step, &tol);
    
    find_roots(start, end, step, tol);
    return 0;
}