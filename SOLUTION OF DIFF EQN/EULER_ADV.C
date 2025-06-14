#include <stdio.h>
#include <math.h>


float derivative(float x, float y) {
    return x + y; // Example: dy/dx = x + y
}

void eulerMethod(float x0, float y0, float h, float x_target) {
    float x = x0;
    float y = y0;
    int step = 1;
    
    printf("Step\t x\t\t y\n");
    printf("----------------------------\n");
    printf("0\t %f\t %f\n", x, y);
    
    while(x < x_target) {
        y = y + h * derivative(x, y);
        x = x + h;
        printf("%d\t %f\t %f\n", step, x, y);
        step++;
    }
    
    printf("\nAt x = %f, y = %f\n", x_target, y);
}

int main() {
    float x0, y0, h, x_target;
    
    printf("Enter initial condition (x0 y0): ");
    scanf("%f %f", &x0, &y0);
    
    printf("Enter step size (h): ");
    scanf("%f", &h);
    
    printf("Enter target x value: ");
    scanf("%f", &x_target);
    
    eulerMethod(x0, y0, h, x_target);
    
    return 0;
}