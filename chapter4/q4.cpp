#include <iostream>

// Function to compute the nth Fibonacci number using a for loop
unsigned long long fibonacci(int n) {
    if (n <= 0) {
        return 0; // Invalid input
    } else if (n == 1) {
        return 1; // Base case: Fibonacci(1) = 1
    }

    unsigned long long fibPrev = 0; // Fibonacci number at n-2
    unsigned long long fibCurrent = 1; // Fibonacci number at n-1

    for (int i = 2; i <= n; i++) {
        unsigned long long fibNext = fibPrev + fibCurrent; // Compute the next Fibonacci number
        fibPrev = fibCurrent;
        fibCurrent = fibNext;
    }

    return fibCurrent; // Fibonacci(n)
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    unsigned long long result = fibonacci(n);
    std::cout << "Fibonacci(" << n << ") = " << result << std::endl;

    return 0;
}
