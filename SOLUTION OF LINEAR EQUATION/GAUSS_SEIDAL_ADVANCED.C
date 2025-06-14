#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define MAX_SIZE 10
#define TOLERANCE 0.0001

// Function to rearrange rows for diagonal dominance
void rearrangeForDiagonalDominance(int n, float a[][MAX_SIZE+1]) {
    for(int col = 0; col < n; col++) {
        // Find row with maximum element in current column
        int max_row = col;
        for(int row = col+1; row < n; row++) {
            if(fabs(a[row][col]) > fabs(a[max_row][col])) {
                max_row = row;
            }
        }
        
        // Swap entire rows (including constant terms) if needed
        if(max_row != col) {
            printf("Swapping rows %d and %d for diagonal dominance\n", col+1, max_row+1);
            for(int j = 0; j <= n; j++) {
                float temp = a[col][j];
                a[col][j] = a[max_row][j];
                a[max_row][j] = temp;
            }
        }
    }
}

// Function to check diagonal dominance
bool isDiagonallyDominant(int n, float a[][MAX_SIZE+1]) {
    for(int i = 0; i < n; i++) {
        float sum = 0.0;
        for(int j = 0; j < n; j++) {
            if(i != j) {
                sum += fabs(a[i][j]);
            }
        }
        if(fabs(a[i][i]) <= sum) {
            return false;
        }
    }
    return true;
}

// Function to print the augmented matrix
void printAugmentedMatrix(int n, float a[][MAX_SIZE+1]) {
    printf("\nCurrent Augmented Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%8.4f ", a[i][j]);
        }
        printf("| %8.4f\n", a[i][n]);  // Constants column
    }
}

int main() {
    int n, max_iter;
    float a[MAX_SIZE][MAX_SIZE+1];  // Augmented matrix (coefficients + constants)
    float x[MAX_SIZE] = {0};       // Solution vector
    
    // Input system of equations
    printf("Enter number of equations (max %d): ", MAX_SIZE);
    scanf("%d", &n);
    
    printf("Enter the augmented matrix (coefficients + constant term):\n");
    for(int i = 0; i < n; i++) {
        printf("Equation %d coefficients and constant (space separated): ", i+1);
        for(int j = 0; j <= n; j++) {
            scanf("%f", &a[i][j]);
        }
    }
    
    // Print original matrix
    printf("\nOriginal Augmented Matrix:");
    printAugmentedMatrix(n, a);
    
    // Check and adjust for diagonal dominance
    if(!isDiagonallyDominant(n, a)) {
        printf("\nMatrix is not diagonally dominant. Attempting to rearrange rows...\n");
        rearrangeForDiagonalDominance(n, a);
        printAugmentedMatrix(n, a);
        
        if(!isDiagonallyDominant(n, a)) {
            printf("\nWarning: Could not achieve strict diagonal dominance. Convergence not guaranteed.\n");
        } else {
            printf("\nSuccessfully rearranged for diagonal dominance.\n");
        }
    }
    
    printf("Enter maximum iterations: ");
    scanf("%d", &max_iter);
    
    // Print iteration table header
    printf("\nIteration Table:\n");
    printf("+--------+");
    for(int i = 0; i < n; i++) printf("-----------+");
    printf("------------+\n");
    
    printf("| Iter   |");
    for(int i = 0; i < n; i++) printf("    x%d     |", i+1);
    printf("   Error   |\n");
    
    printf("+--------+");
    for(int i = 0; i < n; i++) printf("-----------+");
    printf("------------+\n");
    
    // Gauss-Seidel iteration
    for(int k = 1; k <= max_iter; k++) {
        float error = 0;
        float prev_x[MAX_SIZE];
        for(int i = 0; i < n; i++) prev_x[i] = x[i];
        
        for(int i = 0; i < n; i++) {
            float sum = a[i][n];  // Start with constant term
            
            // Subtract all other terms (using newest values)
            for(int j = 0; j < n; j++) {
                if(j != i) sum -= a[i][j] * x[j];
            }
            
            x[i] = sum / a[i][i];
            error += fabs(x[i] - prev_x[i]);
        }
        
        // Print iteration results
        printf("| %-6d |", k);
        for(int i = 0; i < n; i++) printf(" %-9.6f |", x[i]);
        printf(" %-9.6f |\n", error);
        
        // Check for convergence
        if(error < TOLERANCE) {
            printf("+--------+");
            for(int i = 0; i < n; i++) printf("-----------+");
            printf("------------+\n");
            printf("\nConverged after %d iterations!\n", k);
            break;
        }
    }
    
    // Final solution
    printf("\nFinal Solution:\n");
    for(int i = 0; i < n; i++) {
        printf("x%d = %.6f\n", i+1, x[i]);
    }
    
    return 0;
}