#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <limits>

int main()
{
    long double startValue;
    int iterations;

    // Input prompt
    std::cout << "Enter a starting value (long double recommended): ";
    std::cin >> startValue;

    std::cout << "Enter number of iterations: ";
    std::cin >> iterations;

    // Call the sequence generator after input
    generateSequence();

    return 0;
}