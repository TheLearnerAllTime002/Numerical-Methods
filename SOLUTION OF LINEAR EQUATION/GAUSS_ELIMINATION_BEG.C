#include <stdio.h>
#include <math.h>

#define MAX 10

int main() {
    float a[MAX][MAX], x[MAX], ratio;
    int i, j, k, n;

    printf("Enter number of unknowns: ");
    scanf("%d", &n);

    printf("Enter coefficients of Augmented Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j <= n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    /* Forward Elimination */
    for(i = 0; i < n-1; i++) {
        if(fabs(a[i][i]) < 0.0001) {
            printf("Pivot element zero. Cannot solve.\n");
            return 1;
        }
        
        for(j = i+1; j < n; j++) {
            ratio = a[j][i]/a[i][i];
            for(k = 0; k <= n; k++) {
                a[j][k] = a[j][k] - ratio*a[i][k];
            }
        }
    }

    /* Back Substitution */
    x[n-1] = a[n-1][n]/a[n-1][n-1];

    for(i = n-2; i >= 0; i--) {
        x[i] = a[i][n];
        for(j = i+1; j < n; j++) {
            x[i] = x[i] - a[i][j]*x[j];
        }
        x[i] = x[i]/a[i][i];
    }

    /* Display Solution */
    printf("\nSolution:\n");
    for(i = 0; i < n; i++) {
        printf("x[%d] = %.3f\n", i, x[i]);
    }

    return 0;
}