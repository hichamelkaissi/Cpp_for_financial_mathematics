#include <iostream>
#include <cmath>
#include <cstddef>

// Cumulative distribution function for the standard normal distribution
double cumulativeNormalDistribution(double x) {
    return 0.5 * (1.0 + std::erf(x / std::sqrt(2.0)));
}

// Black-Scholes call option pricing function
double blackScholesCallPrice(double strikePrice, double timeToMaturity, double spotPrice, double volatility, double riskFreeRate) {
    // Calculate d1 and d2
    double sigmaSqrtT = volatility * std::sqrt(timeToMaturity);
    double d1 = (std::log(spotPrice / strikePrice) + (riskFreeRate + 0.5 * volatility * volatility) * timeToMaturity) / sigmaSqrtT;
    double d2 = d1 - sigmaSqrtT;

    // Calculate the call option price
    double callPrice = spotPrice * cumulativeNormalDistribution(d1) - strikePrice * std::exp(-riskFreeRate * timeToMaturity) * cumulativeNormalDistribution(d2);

    return callPrice;
}

int main() {
    double strikePrice, timeToMaturity, spotPrice, volatility, riskFreeRate;

    std::cout << "Enter strike price: ";
    std::cin >> strikePrice;
    std::cout << "Enter time to maturity (in years): ";
    std::cin >> timeToMaturity;
    std::cout << "Enter spot price: ";
    std::cin >> spotPrice;
    std::cout << "Enter volatility (as a decimal): ";
    std::cin >> volatility;
    std::cout << "Enter risk-free interest rate (as a decimal): ";
    std::cin >> riskFreeRate;

    double callOptionPrice = blackScholesCallPrice(strikePrice, timeToMaturity, spotPrice, volatility, riskFreeRate);
    std::cout << "Call option price: " << callOptionPrice << std::endl;

    return 0;
}
