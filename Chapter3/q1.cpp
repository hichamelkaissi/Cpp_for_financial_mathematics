#include <iostream>

int sumNumbers(int n) {
    // Base case: If n is 1, return 1 (the sum of the first positive integer).
    if (n == 1) {
        return 1;
    }
    
    // Recursive case: Add n to the sum of numbers from 1 to (n-1).
    return n + sumNumbers(n - 1);
}

int main() {
    int n;
    std::cout << "Enter a positive integer n: ";
    std::cin >> n;

    if (n < 1) {
        std::cout << "Please enter a positive integer." << std::endl;
    } else {
        int result = sumNumbers(n);
        std::cout << "The sum of numbers from 1 to " << n << " is: " << result << std::endl;
    }

    return 0;
}
