#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    try {
        Intern someRandomIntern;
        AForm* form;

        std:: cout<<"**********Creating a RobotomyRequestForm**********"<<std::endl;
        form = someRandomIntern.makeForm("robotomy request", "Bender");
        if (form) {
            std::cout << *form << std::endl;
            delete form;
        }

        std::cout<<"**********Creating a ShrubberyCreationForm**********"<<std::endl;
        form = someRandomIntern.makeForm("shrubbery creation", "Home");
        if (form) {
            std::cout << *form << std::endl;
            delete form;
        }

        std:: cout <<"**********Creating a PresidentialPardonForm**********"<<std::endl;
        form = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
        if (form) {
            std::cout << *form << std::endl;
            delete form;
        }

        std::cout <<"**********Attempting to create a non-existent form**********"<<std::endl;
        form = someRandomIntern.makeForm("unknown form", "Target");
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
