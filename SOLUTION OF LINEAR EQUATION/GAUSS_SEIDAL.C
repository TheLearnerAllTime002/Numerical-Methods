#include <stdio.h>
#include <math.h>

#define MAX_SIZE 10
#define TOLERANCE 0.001

int main() {
    int n, i, j, iterations;
    float a[MAX_SIZE][MAX_SIZE+1]; // Augmented matrix
    float x[MAX_SIZE] = {0};       // Initial guess (all zeros)
    float new_x[MAX_SIZE];         // Updated values
    float error;
    
    // Input the system of equations
    printf("Enter number of equations (max %d): ", MAX_SIZE);
    scanf("%d", &n);
    
    printf("Enter the augmented matrix (coefficients + constants):\n");
    for(i = 0; i < n; i++) {
        printf("Equation %d: ", i+1);
        for(j = 0; j <= n; j++) {
            scanf("%f", &a[i][j]);
        }
    }
    
    // Check diagonal dominance
    for(i = 0; i < n; i++) {
        float sum = 0;
        for(j = 0; j < n; j++) {
            if(j != i) sum += fabs(a[i][j]);
        }
        if(fabs(a[i][i]) <= sum) {
            printf("Warning: System may not converge (not diagonally dominant)\n");
            break;
        }
    }
    
    printf("Enter maximum iterations: ");
    scanf("%d", &iterations);
    
    // Gauss-Seidel iteration
    for(int k = 1; k <= iterations; k++) {
        error = 0;
        
        for(i = 0; i < n; i++) {
            new_x[i] = a[i][n]; // Start with constant term
            
            // Subtract all other terms
            for(j = 0; j < n; j++) {
                if(j != i) {
                    // Use new_x if already calculated in this iteration
                    new_x[i] -= a[i][j] * (j < i ? new_x[j] : x[j]);
                }
            }
            
            new_x[i] /= a[i][i]; // Divide by diagonal element
            
            // Calculate error
            error += fabs(new_x[i] - x[i]);
            x[i] = new_x[i]; // Update immediately (Gauss-Seidel)
        }
        
        // Print current iteration results
        printf("Iteration %d: ", k);
        for(i = 0; i < n; i++) {
            printf("x%d=%.4f  ", i+1, x[i]);
        }
        printf("\n");
        
        // Check for convergence
        if(error < TOLERANCE) {
            printf("\nConverged after %d iterations!\n", k);
            break;
        }
    }
    
    // Final solution
    printf("\nSolution:\n");
    for(i = 0; i < n; i++) {
        printf("x%d = %.4f\n", i+1, x[i]);
    }
    
    return 0;
}