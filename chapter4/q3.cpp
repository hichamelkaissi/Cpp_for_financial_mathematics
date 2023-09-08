#include <iostream>
#include <cmath>

// Function to compute the integral using the rectangle rule
double rectangleRuleIntegral(double x, int n) {
    if (n <= 0) {
        return 0.0; // Invalid input for the number of subintervals
    }

    double h = 1.0 / n; // Width of each subinterval
    double integralApproximation = 0.0;

    for (int i = 0; i < n; i++) {
        double s = i * h; // Left endpoint of the subinterval
        double f_s = ((x + 1 - 1) * (x + 1 - 1)) / 2.0 * std::exp(-s);
        integralApproximation += f_s;
    }

    integralApproximation *= h; // Multiply by the width of each subinterval

    return integralApproximation;
}

int main() {
    double x;
    int n;

    std::cout << "Enter the value of x: ";
    std::cin >> x;
    std::cout << "Enter the number of subintervals n: ";
    std::cin >> n;

    double approximation = rectangleRuleIntegral(x, n);
    std::cout << "Rectangle Rule Approximation: " << approximation << std::endl;

    return 0;
}
