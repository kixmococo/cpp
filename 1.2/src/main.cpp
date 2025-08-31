#include <iostream>
#include <string>
#include <iomanip>   // setw, setprecision
int main() {
    // 1) Full name with spaces
    std::string name{};
    std::cout << "Enter your full name: ";
    std::getline(std::cin >> std::ws, name);

    // 2) Age → birth year via const
    const int CURRENT_YEAR{2025};
    int age{};
    std::cout << "Enter your age: ";
    std::cin >> age;
    int birthYear = CURRENT_YEAR - age;

    // 3) Two numbers
    int a{}, b{};
    std::cout << "Enter two integers: ";
    std::cin >> a >> b;

    // Header
    std::cout << "\nHello, " << name << "! You were born in " << birthYear << ".\n\n";

    // 4) Nicely formatted report
    std::cout << std::left;
    const int W = 20;
    std::cout << std::fixed << std::setprecision(2);

    std::cout << std::setw(W) << "Sum:"        << (a + b) << '\n';
    std::cout << std::setw(W) << "Difference:" << (a - b) << '\n';
    std::cout << std::setw(W) << "Product:"    << (a * b) << '\n';

    if (b != 0) {
        std::cout << std::setw(W) << "Quotient (int):"  << (a / b) << '\n';
        std::cout << std::setw(W) << "Quotient (real):" << static_cast<double>(a) / b << '\n';
        std::cout << std::setw(W) << "Remainder:"       << (a % b) << '\n';
    } else {
        std::cout << std::setw(W) << "Quotient:"  << "undefined (b==0)\n";
        std::cout << std::setw(W) << "Remainder:" << "undefined (b==0)\n";
    }

    return 0;
}

