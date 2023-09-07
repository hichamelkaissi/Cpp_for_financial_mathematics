#include <iostream>
#include <cmath>
#include <vector>

// Horner function with a vector of coefficients
double hornerFunction(double x, const std::vector<double>& coefficients) {
    double result = 0.0;
    for (int i = coefficients.size() - 1; i >= 0; i--) {
        result = result * x + coefficients[i];
    }
    return result;
}

// Calculate the cumulative distribution function (CDF) of the standard normal distribution using Horner's method
double normcdf(double x) {
    // Coefficients for the standard normal distribution CDF
    std::vector<double> coefficients;
    coefficients.push_back(0.319381530);
    coefficients.push_back(-0.356563782);
    coefficients.push_back(1.781477937);
    coefficients.push_back(-1.821255978);
    coefficients.push_back(1.330274429);

    double k = 1.0 / (1.0 + 0.2316419 * x);
    double pi = 3.141592653589793238462643383279502884197;

    double d = 1.0 / sqrt(2.0 * pi);

    // Use the 4th-degree Horner function with a vector of coefficients to simplify the calculation
    double result = d * exp(-pow(x, 2) / 2) * hornerFunction(k, coefficients);

    return (x >= 0) ? result : 1.0 - result;
}

int main() {
    double x;
    std::cout << "Enter a value for x: ";
    std::cin >> x;

    double result = normcdf(x);
    std::cout << "NormCDF(" << x << ") = " << result << std::endl;

    return 0;
}

