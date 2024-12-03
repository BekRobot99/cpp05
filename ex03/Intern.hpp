#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <exception>

class Intern {
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    // Member function
    AForm* makeForm(const std::string& formName, const std::string& target) const;

    // Exception class
    class FormNotFoundException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Error: Form not found!";
        }
    };
};

#endif
