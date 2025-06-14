#include <stdio.h>
#include <math.h>

float derivative(float x, float y) {
    return x * y; // Example: dy/dx = x*y
}

float eulerMethod(float x0, float y0, float h, float x_target) {
    float x = x0;
    float y = y0;
    
    while(x < x_target - h/2) {  
        y = y + h * derivative(x, y);
        x = x + h;
    }
    
    return y;
}

int main() {
    float x0, y0, h, x_target;
    
    printf("Solving ODE using Euler's Method\n");
    printf("--------------------------------\n");
    printf("Enter initial condition (x0 y0): ");
    scanf("%f %f", &x0, &y0);
    
    printf("Enter step size (h): ");
    scanf("%f", &h);
    
    printf("Enter target x value: ");
    scanf("%f", &x_target);
    
    float result = eulerMethod(x0, y0, h, x_target);
    
    printf("\nAt x = %.4f, y ≈ %.6f\n", x_target, result);
    
    return 0;
}