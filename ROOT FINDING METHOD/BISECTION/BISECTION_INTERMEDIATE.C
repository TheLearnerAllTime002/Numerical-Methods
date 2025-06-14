#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001
#define STEP 0.1

double f(double x) {
    return x*x - 4; // Example function: x² - 4 (roots at x = ±2)
}

void print_iteration_table(int root_num, int iteration, double left, double right, double mid, double f_mid) {
    if (iteration == 1) {
        printf("\nRoot %d Bisection Iterations:\n", root_num);
        printf("Iter\tLeft\t\tRight\t\tMid\t\tf(Mid)\t\tError\n");
        printf("-----------------------------------------------------------------\n");
    }
    printf("%d\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\n", 
        iteration, left, right, mid, f_mid, right-left);
}

void find_roots(double a, double b) {
    int root_count = 0;
    int found = 0;
    
    for (double x = a; x <= b; x += STEP) {
        if (f(x) * f(x + STEP) <= 0) {
            root_count++;
            found = 1;
            double left = x, right = x + STEP;
            int iteration = 0;
            
            printf("\nPotential root found in interval [%.4f, %.4f]\n", left, right);
            
            while (right - left > EPSILON) {
                iteration++;
                double mid = (left + right) / 2;
                double f_mid = f(mid);
                
                print_iteration_table(root_count, iteration, left, right, mid, f_mid);
                
                if (f(left) * f(mid) <= 0) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
            
            double root = (left + right) / 2;
            printf("\nRoot %d finalized at: %.6f\n", root_count, root);
            printf("Total iterations: %d\n", iteration);
            printf("Final error: %.6f\n", right-left);
            printf("f(root) = %.6f\n", f(root));
            printf("-------------------------------------------------\n");
        }
    }
    
    if (!found) {
        printf("\nNo roots found in [%.2f, %.2f]. Try another range: ", a, b);
        scanf("%lf %lf", &a, &b);
        find_roots(a, b);
    } else {
        printf("\nFound %d root(s) in the specified range.\n", root_count);
    }
}

int main() {
    double a, b;
    printf("Bisection Method Root Finder\n");
    printf("Function: f(x) = x^2 - 4\n");
    printf("Enter search range [START END]: ");
    scanf("%lf %lf", &a, &b);
    
    find_roots(a, b);
    
    return 0;
}