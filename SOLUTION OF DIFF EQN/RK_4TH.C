#include <stdio.h>
#include <math.h>

// Define the differential equation dy/dx = f(x, y)
double derivative(double x, double y) {
    return x + y; // Example: dy/dx = x + y
}

double rungeKutta4(double x0, double y0, double h, double x_target) {
    double x = x0;
    double y = y0;
    
    while (x < x_target) {
        double k1 = h * derivative(x, y);
        double k2 = h * derivative(x + h/2, y + k1/2);
        double k3 = h * derivative(x + h/2, y + k2/2);
        double k4 = h * derivative(x + h, y + k3);
        
        y = y + (k1 + 2*k2 + 2*k3 + k4)/6;
        x = x + h;
    }
    
    return y;
}

int main() {
    double x0, y0, h, x_target;
    
    printf("Runge-Kutta 4th Order Method\n");
    printf("---------------------------\n");
    
    // Get user inputs
    printf("Enter initial condition (x0 y0): ");
    scanf("%lf %lf", &x0, &y0);
    
    printf("Enter step size (h): ");
    scanf("%lf", &h);
    
    printf("Enter target x value: ");
    scanf("%lf", &x_target);
    
    // Compute solution
    double result = rungeKutta4(x0, y0, h, x_target);
    
    // Display result
    printf("\nAt x = %.4f, y ≈ %.8f\n", x_target, result);
    
    return 0;
}