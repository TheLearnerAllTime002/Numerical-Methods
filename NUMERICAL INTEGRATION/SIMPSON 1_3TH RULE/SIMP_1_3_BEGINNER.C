#include <stdio.h>
#include <math.h>

double f(double x) {
    return 1.0 / sqrt(1.0 + x * x * x);
}

int main() {
    double lower, upper, h, integral = 0.0;
    int subIntervals;

    printf("Enter lower limit of integration: ");
    scanf("%lf", &lower);
    printf("Enter upper limit of integration: ");
    scanf("%lf", &upper);
    
    do {
        printf("Enter number of sub intervals (must be even): ");
        scanf("%d", &subIntervals);
        if (subIntervals % 2 != 0) {
            printf("Error: Number of sub intervals must be even for Simpson's 1/3 rule.\n");
            printf("Please re-enter a correct value.\n");
        }
    } while (subIntervals % 2 != 0);

    h = (upper - lower) / subIntervals;

    integral = f(lower) + f(upper);

    for (int i = 1; i < subIntervals; i++) {
        double x = lower + i * h;
        if (i % 2 == 0) {
            integral += 2 * f(x);
        } else {
            integral += 4 * f(x);
        }
    }

    integral *= h / 3;

    printf("\nApproximate integral value using Simpson's 1/3 rule: %.6lf\n", integral);

    return 0;
}