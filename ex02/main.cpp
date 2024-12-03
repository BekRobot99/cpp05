#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 1);
        ShrubberyCreationForm shrubbery("Garden");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Ford Prefect");

        // Signing forms
        alice.signForm(shrubbery);
        alice.signForm(robotomy);
        alice.signForm(pardon);

        // Executing forms
        alice.executeForm(shrubbery);
        alice.executeForm(robotomy);
        alice.executeForm(pardon);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
