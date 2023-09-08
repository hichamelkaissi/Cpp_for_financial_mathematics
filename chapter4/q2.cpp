#include <iostream>
#include <cmath>

// Function to compute the rectangle rule approximation for the integral of sin(x)
double rectangleRuleApproximation(double a, double b, int n) {
    if (n <= 0 || a >= b) {
        return 0.0; // Invalid input or no subintervals
    }

    double h = (b - a) / n; // Width of each subinterval
    double integralApproximation = 0.0;

    for (int i = 0; i < n; i++) {
        double xi = a + i * h; // Left endpoint of the subinterval
        integralApproximation += std::sin(xi);
    }

    integralApproximation *= h; // Multiply by the width of each subinterval

    return integralApproximation;
}

int main() {
    double a, b;
    int n;

    std::cout << "Enter the lower limit a: ";
    std::cin >> a;
    std::cout << "Enter the upper limit b: ";
    std::cin >> b;
    std::cout << "Enter the number of subintervals n: ";
    std::cin >> n;

    double approximation = rectangleRuleApproximation(a, b, n);
    std::cout << "Rectangle Rule Approximation: " << approximation << std::endl;

    return 0;
}
