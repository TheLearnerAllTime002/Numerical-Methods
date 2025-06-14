#include <stdio.h>

int main() {
    int n, i, j;
    double x, u, h, term, result;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    double xval[n], yval[n], diff[n][n];

    printf("Enter x and y values (space separated):\n");
    for(i = 0; i < n; i++) {
        scanf("%lf %lf", &xval[i], &yval[i]);
    }

    printf("Enter point to interpolate: ");
    scanf("%lf", &x);

    h = xval[1] - xval[0];
    u = (x - xval[0]) / h;

    for(i = 0; i < n; i++) {
        diff[i][0] = yval[i];
    }

    for(j = 1; j < n; j++) {
        for(i = 0; i < n-j; i++) {
            diff[i][j] = diff[i+1][j-1] - diff[i][j-1];
        }
    }

    result = diff[0][0];
    term = 1.0;

    for(i = 1; i < n; i++) {
        term = term * (u - (i-1)) / i;
        result += term * diff[0][i];
    }

    printf("Interpolated value at %.4f is %.6f\n", x, result);

    return 0;
}