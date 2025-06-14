#include <stdio.h>
#include <math.h>

double f(double x) {
    return 1.0 / (1.0 + x * x );
}

int main() {
    double lower, upper, h, integral = 0.0;
    int subIntervals;

    printf("Enter lower limit of integration: ");
    scanf("%lf", &lower);
    printf("Enter upper limit of integration: ");
    scanf("%lf", &upper);
    
    do {
        printf("Enter number of sub intervals (must be multiple of 6): ");
        scanf("%d", &subIntervals);
        if (subIntervals % 6 != 0) {
            printf("Error: Weddle's Rule requires number of sub-intervals to be multiple of 6.\n");
            printf("Please re-enter correct value.\n");
        }
    } while (subIntervals % 6 != 0);

    h = (upper - lower) / subIntervals;

    const int weights[] = {1, 5, 1, 6, 1, 5, 2};
    int weight_index = 0;

    // First point (weight = 1)
    integral += weights[weight_index] * f(lower);
    weight_index = (weight_index + 1) % 7;

    // Middle points
    for (int i = 1; i < subIntervals; i++) {
        double x = lower + i * h;
        integral += weights[weight_index] * f(x);
        weight_index = (weight_index + 1) % 7;
    }

    if (subIntervals % 6 == 0) {
        integral += 1 * f(upper);
    }

    integral *= 3 * h / 10;  // Weddle's rule scaling factor

    printf("\nApproximate integral value using Weddle's Rule: %.6lf\n", integral);

    return 0;
}