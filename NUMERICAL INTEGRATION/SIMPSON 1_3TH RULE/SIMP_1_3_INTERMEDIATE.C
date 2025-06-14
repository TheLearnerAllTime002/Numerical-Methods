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
    
    // Ensure subIntervals is even (required for Simpson's 1/3 rule)
    do {
        printf("Enter number of sub intervals (must be even): ");
        scanf("%d", &subIntervals);
        if (subIntervals % 2 != 0) {
            printf("Error: Number of sub intervals must be even for Simpson's 1/3 rule.\n");
            printf("Please re-enter a correct value.\n");
        }
    } while (subIntervals % 2 != 0);

    h = (upper - lower) / subIntervals;

    printf("\n%10s %12s %15s %15s\n", "x", "f(x)", "Weight", "Contribution");
    printf("--------------------------------------------\n");

    // First term (weight = 1)
    integral = f(lower);
    printf("%10.4lf %12.6lf %15.1lf %15.6lf\n", lower, f(lower), 1.0, f(lower));

    // Middle terms (alternating weights 4 and 2)
    for (int i = 1; i < subIntervals; i++) {
        double x = lower + i * h;
        double fx = f(x);
        double weight = (i % 2 == 1) ? 4.0 : 2.0; // 4 for odd, 2 for even
        integral += weight * fx;
        printf("%10.4lf %12.6lf %15.1lf %15.6lf\n", x, fx, weight, weight * fx);
    }

    // Last term (weight = 1)
    integral += f(upper);
    printf("%10.4lf %12.6lf %15.1lf %15.6lf\n", upper, f(upper), 1.0, f(upper));

    integral *= h / 3.0; // Simpson's 1/3 rule factor

    printf("\nApproximate integral value using Simpson's 1/3 rule: %.6lf\n", integral);

    return 0;
}