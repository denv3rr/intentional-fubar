#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <limits>

void generateSequence(long double startValue, int iterations)
{
    std::vector<long double> sequence; // Dynamic allocation through vector
    sequence.reserve(iterations);      // Reserve memory up-front

    long double current = startValue;

    std::cout << "\nStarting value: " << std::setprecision(18) << current << "\n\n";
    for (int i = 0; i < iterations; ++i)
    {
        // Strange recursive formula
        current = std::sin(current * current) * std::tan(current) + std::sqrt(std::abs(current));
        sequence.push_back(current);

        // Print the current value
        std::cout << "Iteration " << i + 1 << ": " << std::setprecision(18) << current << "\n";

        // Watch for overflows, NaN, or infinities
        if (std::isnan(current))
        {
            std::cerr << "NaN detected at iteration " << i + 1 << "!\n";
            break;
        }
        else if (std::isinf(current))
        {
            std::cerr << "Infinity detected at iteration " << i + 1 << "!\n";
            break;
        }
    }

    std::cout << "\nFinal sequence size: " << sequence.size() << "\n\n";
}

int main()
{
    long double startValue;
    int iterations;

    // Input prompt
    std::cout << "\nEnter a starting value (long double recommended): ";
    std::cin >> startValue;

    std::cout << "Enter number of iterations: ";
    std::cin >> iterations;

    // Call the sequence generator after input
    generateSequence(startValue, iterations);

    return 0;
}