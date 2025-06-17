// #include <stdio.h>
// #include <math.h>

// #define EPSILON 0.0001
// #define STEP 0.1

// double f(double x) {
//     return x*x - 4; // Change this to your desired function
// }

// void find_roots(double a, double b) {
//     int found = 0;
//     for (double x = a; x <= b; x += STEP) {
//         if (f(x) * f(x + STEP) <= 0) {
//             double left = x, right = x + STEP;
//             while (right - left > EPSILON) {
//                 double mid = (left + right) / 2;
//                 if (f(left) * f(mid) <= 0) {
//                     right = mid;
//                 } else {
//                     left = mid;
//                 }
//             }
//             printf("Root found at: %.4f\n", (left + right)/2);
//             found = 1;
//         }
//     }
//     if (!found) {
//         printf("No roots found in [%.2f, %.2f]. Try another range: ", a, b);
//         scanf("%lf %lf", &a, &b);
//         find_roots(a, b);
//     }
// }

// int main() {
//     double a, b;
//     printf("Enter range [START END]: ");
//     scanf("%lf %lf", &a, &b);
//     find_roots(a, b);
//     return 0;
// }

#include <stdio.h>
#include <math.h>

#define EPS 0.0001f
#define STEP 0.1f

float f(float x) {
    return x * x - 4;  // f(x) = x^2 - 4
}

void find_roots(float a, float b) {
    int found = 0;
    for (float x = a; x <= b; x += STEP) {
        if (f(x) * f(x + STEP) <= 0) {
            float l = x, r = x + STEP;
            while (r - l > EPS) {
                float m = (l + r) / 2;
                if (f(l) * f(m) <= 0)
                    r = m;
                else
                    l = m;
            }
            printf("Root: %.4f\n", (l + r) / 2);
            found = 1;
        }
    }
    if (!found) {
        printf("No root found. Enter new range: ");
        scanf("%f %f", &a, &b);
        find_roots(a, b);
    }
}

int main() {
    float a, b;
    printf("Enter range: ");
    scanf("%f %f", &a, &b);
    find_roots(a, b);
    return 0;
}

