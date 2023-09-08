#include <iostream>
#include <cmath>
#include <stdexcept> // Include the <stdexcept> header for exception handling

// Constants for the Moro algorithm
const double a0 = 2.50662823884;
const double a1 = -18.61500062529;
const double a2 = 41.39119773534;
const double a3 = -25.44106049637;
const double b1 = -8.47351093090;
const double b2 = 23.08336743743;
const double b3 = -21.06224101826;
const double b4 = 3.13082909833;
const double c0 = 0.3374754822726147;
const double c1 = 0.9761690190917186;
const double c2 = 0.1607979714918209;
const double c3 = 0.0276438810333863;
const double c4 = 0.0038405729373609;
const double c5 = 0.0003951896511919;
const double c6 = 0.0000321767881768;
const double c7 = 0.0000002888167364;
const double c8 = 0.0000003960315187;

// Horner function with a variable number of coefficients
double hornerFunction(double x, const double* coefficients, int degree) {
    double result = coefficients[degree];
    for (int i = degree - 1; i >= 0; i--) {
        result = result * x + coefficients[i];
    }
    return result;
}

// Function to calculate the cumulative distribution function for the standard normal distribution
double cumulativeNormalDistribution(double x) {
    return 0.5 * (1.0 + std::erf(x / std::sqrt(2.0)));
}

// Improved norminv function that throws an error for invalid input
double norminv(double x) {
    if (x < 0.0 || x > 1.0) {
        throw std::invalid_argument("Input value x must be within the range [0, 1]");
    }

    double y = x - 0.5;
    double r, s, t;

    if (std::abs(y) < 0.42) {
        r = y * y;
        const double aCoefficients[] = {a0, a1, a2, a3};
        const double bCoefficients[] = {1.0, b1, b2, b3, b4};
        t = y * hornerFunction(r, aCoefficients, 3) / hornerFunction(r, bCoefficients, 4);
    } else {
        if (y < 0) {
            r = x;
        } else {
            r = 1 - x;
        }

        s = -std::log(-std::log(r));
        const double cCoefficients[] = {c0, c1, c2, c3, c4, c5, c6, c7, c8};
        t = hornerFunction(s, cCoefficients, 8);
    }

    return (x > 0.5) ? t : -t;
}

int main() {
    double x;
    try {
        std::cout << "Enter a value for x: ";
        std::cin >> x;

        double result = norminv(x);
        std::cout << "NormInv(" << x << ") = " << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

