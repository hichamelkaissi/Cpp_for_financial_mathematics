#include <iostream>

void printNumbers(int a, int b) {
    // Base case: If a is greater than b, stop the recursion.
    if (a > b) {
        return;
    }

    // Print the current value of 'a'.
    std::cout << a << " ";

    // Recursively call the function with 'a+1' and 'b'.
    printNumbers(a + 1, b);
}

int main() {
    int a, b;
    std::cout << "Enter two integers (a and b): ";
    std::cin >> a >> b;

    if (a > b) {
        std::cout << "a should be less than or equal to b." << std::endl;
    } else {
        std::cout << "Numbers from " << a << " to " << b << ": ";
        printNumbers(a, b);
        std::cout << std::endl;
    }

    return 0;
}
