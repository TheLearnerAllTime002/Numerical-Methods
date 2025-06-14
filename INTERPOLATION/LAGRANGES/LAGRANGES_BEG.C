#include <stdio.h>

int main() {
    int n, i, j;
    double x, result = 0.0, term;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    double xval[n], yval[n];

    printf("Enter x and y values (space separated):\n");
    for(i = 0; i < n; i++) {
        scanf("%lf %lf", &xval[i], &yval[i]);
    }

    printf("Enter point to interpolate: ");
    scanf("%lf", &x);

    // Lagrange interpolation formula
    for(i = 0; i < n; i++) {
        term = yval[i];
        for(j = 0; j < n; j++) {
            if(j != i) {
                term *= (x - xval[j])/(xval[i] - xval[j]);
            }
        }
        result += term;
    }

    printf("Interpolated value at %.4f is %.4f\n", x, result);

    return 0;
}