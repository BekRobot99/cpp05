#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class Bureaucrat {
public:
    // Nested exception classes
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

    const std::string& getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();
    void signForm(AForm& form) const;
    void executeForm(const AForm& form) const;

private:
    const std::string name;
    int grade;

    void validateGrade(int grade);
};

// Overload of the insertion operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
