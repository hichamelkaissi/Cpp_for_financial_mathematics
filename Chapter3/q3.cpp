#include <iostream>

int fibonacci(int n) {
    if (n <= 1) {
        return 1; // x0 and x1 are both defined as 1
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "Please enter a non-negative integer." << std::endl;
    } else {
        int result = fibonacci(n);
        std::cout << "The " << n << "-th Fibonacci number is: " << result << std::endl;
    }

    return 0;
}
