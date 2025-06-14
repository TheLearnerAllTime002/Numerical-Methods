#include <stdio.h>

int main() {
    int n, i, j;
    double x, v, h, term, result;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    double xval[n], yval[n], diff[n][n];

    // Input data points
    printf("Enter x and y values (space separated):\n");
    for(i = 0; i < n; i++) {
        scanf("%lf %lf", &xval[i], &yval[i]);
        diff[i][0] = yval[i]; // Initialize first differences
    }

    printf("\nEnter point to interpolate: ");
    scanf("%lf", &x);

    // Calculate step size and v
    h = xval[1] - xval[0];
    v = (x - xval[n-1]) / h;

    // Calculate backward differences
    printf("\nBackward Difference Table:\n");
    printf("x\t\ty\t\t∇y\t\t∇2y\t\t∇3y\t\t...\n");
    
    for(j = 1; j < n; j++) {
        for(i = n-1; i >= j; i--) {
            diff[i][j] = diff[i][j-1] - diff[i-1][j-1];
        }
    }

    // Print the difference table
    for(i = 0; i < n; i++) {
        printf("%.4f\t", xval[i]);
        for(j = 0; j <= i; j++) {
            printf("%.4f\t", diff[i][j]);
        }
        printf("\n");
    }

    // Apply Newton's backward formula
    result = diff[n-1][0];
    term = 1.0;

    printf("\nInterpolation Calculation:\n");
    printf("Initial value: yn = %.4f\n", result);
    
    for(i = 1; i < n; i++) {
        term = term * (v + (i-1)) / i;
        printf("Term %d: v=%f, term=%.4f, ∇%dyn=%.4f, adding %.4f\n", 
               i, v, term, i, diff[n-1][i], term * diff[n-1][i]);
        result += term * diff[n-1][i];
    }

    printf("\nFinal interpolated value at %.4f is %.4f\n", x, result);

    return 0;
}