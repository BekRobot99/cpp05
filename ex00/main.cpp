#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 1);
        std::cout << alice << std::endl;
        alice.incrementGrade();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat bob("Bob", 150);
        std::cout << bob << std::endl;
        bob.decrementGrade();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat invalid("Invalid", 151);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
