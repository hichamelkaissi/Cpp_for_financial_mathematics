#include <iostream>
#include <cmath>

double normcdf(double x) {
    if (x >= 0) {
        double k = 1.0 / (1.0 + 0.2316419 * x);
        double pi = 3.141592653589793238462643383279502884197;
        double N;
        double d = 1.0 / sqrt(2.0 * pi);

        N = d * exp(-pow(x, 2) / 2) * k * (0.319381530 + k * (-0.356563782 + k *
        (1.781477937 + k * (-1.821255978 + 1.330274429 * k))));

        return N;
    } else {
        return 1 - normcdf(-x);
    }
}

int main() {
    double x;
    std::cout << "Enter a value for x: ";
    std::cin >> x;

    double result = normcdf(x);
    std::cout << "NormCDF(" << x << ") = " << result << std::endl;

    return 0;
}
