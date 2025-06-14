#include <stdio.h>
#include <math.h>

double f(double x) { return x*x*x - 8*x - 4; }
double df(double x) { return 3*x*x - 8; }

void print_iteration(int iter, double x, double fx, double error) {
    if (iter == 1) {
        printf("\nIteration Table:\n");
        printf("-------------------------------------------------\n");
        printf("Iteration\t x\t\t f(x)\t\t Error\n");
        printf("-------------------------------------------------\n");
    }
    printf("%5d\t %12.6f\t %12.6f\t %12.6f\n", iter, x, fx, error);
}

int newton_raphson(double x0, double tol, int max_iter, double* root) {
    double x = x0;
    for (int i = 1; i <= max_iter; i++) {
        double fx = f(x), dfx = df(x);
        double error = fabs(fx);
        
        print_iteration(i, x, fx, error);

        if (error < tol) {
            *root = x;
            return 1; // Success
        }
        if (dfx == 0) {
            return 0; // Derivative zero
        }
        x = x - fx/dfx;
    }
    return 0; // Max iterations reached
}

void find_roots_range(double a, double b, double step, double tol, int max_iter) {
    double roots[3];
    int found = 0;

    for (double x = a; x < b && found < 3; x += step) {
        if (f(x) * f(x + step) > 0) continue;

        double root;
        printf("\nSearching in [%.2f, %.2f]:", x, x+step);
        if (newton_raphson((x+x+step)/2, tol, max_iter, &root)) {
            int is_new = 1;
            for (int i = 0; i < found; i++) {
                if (fabs(root - roots[i]) < tol) {
                    is_new = 0;
                    break;
                }
            }
            if (is_new) {
                roots[found++] = root;
                printf("\n--> Root found: %.6f\n", root);
            }
        }
    }

    if (found == 0) {
        printf("\nNo roots found in [%.2f, %.2f].\n", a, b);
    }
}

int main() {
    int choice;
    double a, b, step, tol, x0;
    int max_iter;

    while (1) {
        printf("\nChoose method:\n");
        printf("1. Single initial guess\n");
        printf("2. Range search with step size\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 3) break;

        printf("Enter tolerance: ");
        scanf("%lf", &tol);
        printf("Enter max iterations: ");
        scanf("%d", &max_iter);

        if (choice == 1) {
            printf("Enter initial guess: ");
            scanf("%lf", &x0);
            
            double root;
            if (newton_raphson(x0, tol, max_iter, &root)) {
                printf("\nRoot found: %.6f\n", root);
            } else {
                printf("\nNo convergence with given parameters.\n");
            }
        }
        else if (choice == 2) {
            printf("Enter range [a b]: ");
            scanf("%lf %lf", &a, &b);
            if (a >= b) {
                printf("Invalid range (a must be < b)\n");
                continue;
            }
            printf("Enter step size: ");
            scanf("%lf", &step);
            find_roots_range(a, b, step, tol, max_iter);
        }
        else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}