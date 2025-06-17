// #include <stdio.h>
// #include <math.h>

// #define TOL 0.0001
// #define STEP 0.1
// #define MAX_ITER 100

// double f(double x) { return x*x*x - 8*x - 4; }
// double df(double x) { return 3*x*x - 8; }

// double newton_raphson(double x0) {
//     double x = x0;
//     for (int i = 0; i < MAX_ITER; i++) {
//         double fx = f(x), dfx = df(x);
//         if (fabs(fx) < TOL) return x;
//         if (dfx == 0) return NAN; // Avoid division by zero
//         x = x - fx / dfx;
//     }
//     return NAN;
// }

// void find_roots(double a, double b) {
//     double roots[3];
//     int found = 0;

//     for (double x = a; x <= b && found < 3; x += STEP) {
//         if (f(x) * f(x + STEP) > 0) continue; // No sign change, skip
//         double root = newton_raphson((x + x + STEP) / 2);
//         if (!isnan(root)) {
//             // Check if root is new (avoid duplicates)
//             int is_new = 1;
//             for (int i = 0; i < found; i++) {
//                 if (fabs(root - roots[i]) < TOL) {
//                     is_new = 0;
//                     break;
//                 }
//             }
//             if (is_new) {
//                 roots[found++] = root;
//                 printf("Root found: %.4f\n", root);
//             }
//         }
//     }

//     if (found == 0) {
//         printf("No roots found in [%.1f, %.1f]. Try another range.\n", a, b);
//     }
// }

// int main() {
//     double a, b;
//     while (1) {
//         printf("Enter range [a b]: ");
//         scanf("%lf %lf", &a, &b);
//         if (a >= b) {
//             printf("Invalid range (a must be < b). Try again.\n");
//             continue;
//         }
//         find_roots(a, b);
//     }
//     return 0;
// }



#include <stdio.h>
#include <math.h>

float f(float x)  { return x*x*x - 8*x - 4; }
float df(float x) { return 3*x*x - 8; }

float newton(float x) {
    for (int i = 0; i < 100; i++) {
        float fx = f(x), dfx = df(x);
        if (fabsf(fx) < 0.0001) return x;
        if (dfx == 0) return NAN;
        x = x - fx / dfx;
    }
    return NAN;
}

void find_roots(float a, float b) {
    float roots[3];
    int found = 0;

    for (float x = a; x <= b && found < 3; x += 0.1) {
        if (f(x) * f(x + 0.1) > 0) continue;

        float guess = (x + x + 0.1) / 2;
        float root = newton(guess);

        if (!isnan(root)) {
            int unique = 1;
            for (int i = 0; i < found; i++) {
                if (fabsf(root - roots[i]) < 0.0001) {
                    unique = 0;
                    break;
                }
            }
            if (unique) {
                roots[found++] = root;
                printf("Root: %.4f\n", root);
            }
        }
    }

    if (!found)
        printf("No root found in [%.1f, %.1f]. Try again.\n", a, b);
}

int main() {
    float a, b;
    while (1) {
        printf("Enter range: ");
        scanf("%f %f", &a, &b);
        if (a >= b) {
            printf("Invalid range. Try again.\n");
            continue;
        }
        find_roots(a, b);
    }
    return 0;
}

