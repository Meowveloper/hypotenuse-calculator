#include <iostream>
#include <cmath>
#include <limits> // for numeric_limits

int main () {
    double a = 0; 
    double b = 0;
    double c = 0;

    auto get_positive_double = [] (const char* prompt) {
        double value;
        while (true) {
            std::cout << prompt;
            std::cin >> value;

            if (std::cin.fail() || value <= 0) {
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                std::cout << "Invalid input! Please enter a positive number.\n";
            } else {
                break; 
            }
        }
        return value;
    };

    a = get_positive_double("Enter side A: ");
    b = get_positive_double("Enter side B: ");
    
    c = sqrt(pow(a, 2) + pow(b, 2)); // c = square root of {(a * a) + (b * b)}
    
    std::cout << "Side C: " << c << '\n';

    return 0;
}
