#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    const std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    // Cast lambdas to return AForm* to avoid type conversion issues
    AForm* (*formCreators[])(const std::string&) = {
        [](const std::string& target) -> AForm* { return new ShrubberyCreationForm(target); },
        [](const std::string& target) -> AForm* { return new RobotomyRequestForm(target); },
        [](const std::string& target) -> AForm* { return new PresidentialPardonForm(target); }
    };

    for (size_t i = 0; i < 3; ++i) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);
        }
    }

    throw FormNotFoundException();
}
