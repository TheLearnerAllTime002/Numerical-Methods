#include <stdio.h>
#include <math.h>

double f(double x) { return x*x*x - 8*x - 4; }
double df(double x) { return 3*x*x - 8; }

void newton_raphson(double x0, double tol, int max_iter) {
    printf("\nIteration Table for x0 = %.4f:\n", x0);
    printf("-------------------------------------------------\n");
    printf("Iteration\t x\t\t f(x)\t\t Error\n");
    printf("-------------------------------------------------\n");

    double x = x0;
    for (int i = 0; i < max_iter; i++) {
        double fx = f(x), dfx = df(x);
        double error = fabs(fx);
        
        printf("%5d\t %12.6f\t %12.6f\t %12.6f\n", i+1, x, fx, error);

        if (error < tol) {
            printf("\nRoot found: %.6f (after %d iterations)\n", x, i+1);
            return;
        }
        if (dfx == 0) {
            printf("\nDerivative zero. No convergence.\n");
            return;
        }
        x = x - fx / dfx;
    }
    printf("\nMax iterations reached. No convergence.\n");
}

int find_roots(double a, double b, double step, double tol, int max_iter) {
    double roots[3];
    int found = 0;

    for (double x = a; x <= b && found < 3; x += step) {
        if (f(x) * f(x + step) > 0) continue; // Skip if no sign change

        double x0 = (x + x + step) / 2; // Midpoint as initial guess
        newton_raphson(x0, tol, max_iter);

        double root = x0;
        for (int i = 0; i < max_iter; i++) {
            double fx = f(root), dfx = df(root);
            if (fabs(fx) < tol) break;
            if (dfx == 0) break;
            root = root - fx / dfx;
        }

        if (fabs(f(root)) < tol) {
            int is_new = 1;
            for (int i = 0; i < found; i++) {
                if (fabs(root - roots[i]) < tol) {
                    is_new = 0;
                    break;
                }
            }
            if (is_new) roots[found++] = root;
        }
    }

    if (found == 0) {
        printf("\nNo roots found in [%.2f, %.2f].\n", a, b);
        return 0; // Indicate no roots found
    }
    return 1; // Roots found
}

int main() {
    double a, b, step, tol;
    int max_iter;

    while (1) { // Infinite loop until valid roots are found
        printf("\nEnter range [a b]: ");
        scanf("%lf %lf", &a, &b);
        if (a >= b) {
            printf("Error: 'a' must be less than 'b'.\n");
            continue;
        }

        printf("Enter step size: ");
        scanf("%lf", &step);
        printf("Enter tolerance: ");
        scanf("%lf", &tol);
        printf("Enter max iterations: ");
        scanf("%d", &max_iter);

        if (find_roots(a, b, step, tol, max_iter)) {
            break; // Exit loop if roots found
        }
        printf("Try another range or adjust parameters.\n");
    }

    return 0;
}