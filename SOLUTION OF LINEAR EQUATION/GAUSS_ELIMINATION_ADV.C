#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define MAX_SIZE 10
#define EPSILON 1e-12  // More precise epsilon for floating-point comparison

void printMatrix(int n, float a[][MAX_SIZE+1]) {
    printf("\nCurrent Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%10.6f ", a[i][j]);
        }
        printf("| %10.6f\n", a[i][n]);
    }
}

bool partialPivot(int n, float a[][MAX_SIZE+1], int k) {
    int max_row = k;
    float max_val = fabs(a[k][k]);
    
    for(int i = k+1; i < n; i++) {
        if(fabs(a[i][k]) > max_val) {
            max_val = fabs(a[i][k]);
            max_row = i;
        }
    }
    
    if(max_row != k) {
        printf("Swapping row %d with row %d\n", k+1, max_row+1);
        for(int j = 0; j <= n; j++) {
            float temp = a[k][j];
            a[k][j] = a[max_row][j];
            a[max_row][j] = temp;
        }
        return true;
    }
    return false;
}

int gaussElimination(int n, float a[][MAX_SIZE+1], float x[]) {
    int singular = 0;
    
    for(int k = 0; k < n; k++) {
        if(fabs(a[k][k]) < EPSILON) {
            if(!partialPivot(n, a, k)) {
                singular = 1;
                break;
            }
        }
        
        for(int i = k+1; i < n; i++) {
            float factor = a[i][k]/a[k][k];
            for(int j = k; j <= n; j++) {
                a[i][j] -= factor * a[k][j];
            }
        }
        
        printf("\nAfter elimination step %d:", k+1);
        printMatrix(n, a);
    }
    
    if(singular) {
        printf("\nSystem is singular (no unique solution exists)\n");
        return 0;  // Return 0 to indicate failure
    }
    
    // Back substitution
    for(int i = n-1; i >= 0; i--) {
        x[i] = a[i][n];
        for(int j = i+1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] = x[i]/a[i][i];
    }
    
    return 1;  // Return 1 to indicate success
}

int main() {
    int n;
    float a[MAX_SIZE][MAX_SIZE+1];
    float x[MAX_SIZE];
    
    printf("Enter number of equations (max %d): ", MAX_SIZE);
    scanf("%d", &n);
    
    if(n <= 0 || n > MAX_SIZE) {
        printf("Invalid number of equations.\n");
        return 1;
    }
    
    printf("Enter augmented matrix (coefficients + constants):\n");
    for(int i = 0; i < n; i++) {
        printf("Row %d: ", i+1);
        for(int j = 0; j <= n; j++) {
            if(scanf("%f", &a[i][j]) != 1) {
                printf("Invalid input.\n");
                return 1;
            }
        }
    }
    
    printf("\nInitial augmented matrix:");
    printMatrix(n, a);
    
    if(!gaussElimination(n, a, x)) {
        return 1;  // Exit if system is singular
    }
    
    printf("\nSolution:\n");
    for(int i = 0; i < n; i++) {
        printf("x[%d] = %12.8f\n", i, x[i]);
    }
    
    return 0;
}