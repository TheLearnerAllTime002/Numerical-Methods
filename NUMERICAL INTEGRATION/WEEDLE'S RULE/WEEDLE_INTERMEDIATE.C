#include <stdio.h>
#include <math.h>

double f(double x) {
    return 1.0 / (1.0 + pow (x,2));
}

int main() {
    double lower, upper, h, integral = 0.0;
    int subIntervals;

    printf("Enter lower limit of integration: ");
    scanf("%lf", &lower);
    printf("Enter upper limit of integration: ");
    scanf("%lf", &upper);
    
    // Ensure subIntervals is a multiple of 6 (required for Weddle's rule)
    do {
        printf("Enter number of sub intervals (must be a multiple of 6): ");
        scanf("%d", &subIntervals);
        if (subIntervals % 6 != 0) {
            printf("Error: Number of sub intervals must be a multiple of 6 for Weddle's rule.\n");
            printf("Please re-enter a correct value.\n");
        }
    } while (subIntervals % 6 != 0);

    h = (upper - lower) / subIntervals;

    printf("\n%10s %12s %15s %15s\n", "x", "f(x)", "Weight", "Contribution");
    printf("--------------------------------------------\n");

    // Weddle's rule weights: 1, 5, 1, 6, 1, 5, 2 (repeats every 6 intervals)
    const int weights[] = {1, 5, 1, 6, 1, 5, 2};
    int weight_index = 0;

    // First point (weight = 1)
    double fx = f(lower);
    integral += weights[weight_index] * fx;
    printf("%10.4lf %12.6lf %15d %15.6lf\n", lower, fx, weights[weight_index], weights[weight_index] * fx);
    weight_index = (weight_index + 1) % 7;

    // Middle points
    for (int i = 1; i < subIntervals; i++) {
        double x = lower + i * h;
        fx = f(x);
        integral += weights[weight_index] * fx;
        printf("%10.4lf %12.6lf %15d %15.6lf\n", x, fx, weights[weight_index], weights[weight_index] * fx);
        weight_index = (weight_index + 1) % 7;
    }

    // Last point (weight = 1 if not already accounted for)
    if (subIntervals % 6 == 0) {
        fx = f(upper);
        integral += 1 * fx;  // Last point in Weddle's rule has weight 1
        printf("%10.4lf %12.6lf %15d %15.6lf\n", upper, fx, 1, 1 * fx);
    }

    integral *= 3 * h / 10;  // Weddle's rule scaling factor

    printf("\nApproximate integral value using Weddle's rule: %.6lf\n", integral);

    return 0;
}