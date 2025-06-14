#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001
#define STEP 0.1

double f(double x) {
    return x*x - 4; // Change this to your desired function
}

void find_roots(double a, double b) {
    int found = 0;
    for (double x = a; x <= b; x += STEP) {
        if (f(x) * f(x + STEP) <= 0) {
            double left = x, right = x + STEP;
            while (right - left > EPSILON) {
                double mid = (left + right) / 2;
                if (f(left) * f(mid) <= 0) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
            printf("Root found at: %.4f\n", (left + right)/2);
            found = 1;
        }
    }
    if (!found) {
        printf("No roots found in [%.2f, %.2f]. Try another range: ", a, b);
        scanf("%lf %lf", &a, &b);
        find_roots(a, b);
    }
}

int main() {
    double a, b;
    printf("Enter range [START END]: ");
    scanf("%lf %lf", &a, &b);
    find_roots(a, b);
    return 0;
}