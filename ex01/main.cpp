#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat john("John", 42);
        Form taxForm("TaxForm", 50, 30);

        std::cout << john << std::endl;
        std::cout << taxForm << std::endl;

        john.signForm(taxForm);

        std::cout << taxForm << std::endl;

        Bureaucrat jane("Jane", 60);
        jane.signForm(taxForm);

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
