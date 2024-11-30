#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

class Bureaucrat {
public:
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Bureaucrat grade is too high!";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Bureaucrat grade is too low!";
        }
    };

    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    // Member functions
    const std::string& getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(Form& form) const;

private:
    const std::string name;
    int grade;

    void validateGrade(int grade);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
