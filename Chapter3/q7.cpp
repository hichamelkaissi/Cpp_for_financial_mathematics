#include <iostream>
#include <cmath>

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

// Moro algorithm for norminv
double norminv(double x) {
    double y = x - 0.5;
    double r, s, t;

    if (std::abs(y) < 0.42) {
        r = y * y;
        t = y * (((a3 * r + a2) * r + a1) * r + a0) / ((((b4 * r + b3) * r + b2) * r + b1) * r + 1.0);
    } else {
        if (y < 0) {
            r = x;
        } else {
            r = 1 - x;
        }

        s = -log(r);
        t = (((((c8 * s + c7) * s + c6) * s + c5) * s + c4) * s + c3) * s + c2;
        t = (t * s + c1) * s + c0;
    }

    return (x > 0.5) ? t : -t;
}

int main() {
    double x;
    std::cout << "Enter a value for x: ";
    std::cin >> x;

    double result = norminv(x);
    std::cout << "NormInv(" << x << ") = " << result << std::endl;

    return 0;
}
