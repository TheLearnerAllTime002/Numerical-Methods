#include <stdio.h>

int main() {
    int n, i, j;
    double x, u, h, term, result;

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

    // Calculate step size and u
    h = xval[1] - xval[0];
    u = (x - xval[0]) / h;

    // Calculate and print forward difference table
    printf("\nForward Difference Table:\n");
    printf("x\t\ty\t\tΔy\t\tΔ2y\t\tΔ3y\t\t...\n");
    
    for(j = 1; j < n; j++) {
        for(i = 0; i < n-j; i++) {
            diff[i][j] = diff[i+1][j-1] - diff[i][j-1];
        }
    }

    // Print the difference table
    for(i = 0; i < n; i++) {
        printf("%.4f\t", xval[i]);
        for(j = 0; j < n-i; j++) {
            printf("%.4f\t", diff[i][j]);
        }
        printf("\n");
    }

    // Apply Newton's forward formula
    result = diff[0][0];
    term = 1.0;

    printf("\nInterpolation Calculation:\n");
    printf("Initial value: y0 = %.4f\n", result);
    
    for(i = 1; i < n; i++) {
        term = term * (u - (i-1)) / i;
        printf("Term %d: u=%f, term=%.4f, Δ%dy0=%.4f, adding %.4f\n", 
               i, u, term, i, diff[0][i], term * diff[0][i]);
        result += term * diff[0][i];
    }

    printf("\nFinal interpolated value at %.4f is %.4f\n", x, result);

    return 0;
}