#include <stdio.h>
#include <math.h>

#define MAX_SIZE 10
#define TOLERANCE 0.0001

int main() {
    int n, i, j, k, max_iter;
    float a[MAX_SIZE][MAX_SIZE+1]; // Augmented matrix
    float x[MAX_SIZE] = {0};      // Solution vector (initialized to 0)
    float prev_x[MAX_SIZE];       // Previous iteration values
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
    
    printf("Enter maximum iterations: ");
    scanf("%d", &max_iter);
    
    // Print table header
    printf("\nIteration Table:\n");
    printf("+--------+");
    for(i = 0; i < n; i++) {
        printf("-----------+");
    }
    printf("------------+\n");
    
    printf("| Iter   |");
    for(i = 0; i < n; i++) {
        printf("    x%d     |", i+1);
    }
    printf("   Error   |\n");
    
    printf("+--------+");
    for(i = 0; i < n; i++) {
        printf("-----------+");
    }
    printf("------------+\n");
    
    // Gauss-Seidel iteration
    for(k = 1; k <= max_iter; k++) {
        error = 0;
        
        // Save previous values
        for(i = 0; i < n; i++) {
            prev_x[i] = x[i];
        }
        
        // Update each variable
        for(i = 0; i < n; i++) {
            float sum = a[i][n]; // Start with constant term
            
            // Subtract all other terms
            for(j = 0; j < n; j++) {
                if(j != i) {
                    sum -= a[i][j] * x[j];
                }
            }
            
            x[i] = sum / a[i][i];
            
            // Calculate error
            error += fabs(x[i] - prev_x[i]);
        }
        
        // Print iteration row
        printf("| %-6d |", k);
        for(i = 0; i < n; i++) {
            printf(" %-9.6f |", x[i]);
        }
        printf(" %-9.6f |\n", error);
        
        // Check for convergence
        if(error < TOLERANCE) {
            printf("+--------+");
            for(i = 0; i < n; i++) {
                printf("-----------+");
            }
            printf("------------+\n");
            printf("\nConverged after %d iterations!\n", k);
            break;
        }
    }
    
    if(k > max_iter) {
        printf("+--------+");
        for(i = 0; i < n; i++) {
            printf("-----------+");
        }
        printf("------------+\n");
        printf("\nMaximum iterations reached without convergence.\n");
    }
    
    // Final solution
    printf("\nFinal Solution:\n");
    for(i = 0; i < n; i++) {
        printf("x%d = %.6f\n", i+1, x[i]);
    }
    
    return 0;
}