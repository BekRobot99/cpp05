#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat {
private:
    const std::string name;
    int grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    // Getters
    const std::string& getName() const;
    int getGrade() const;

    // Modifiers
    void incrementGrade();
    void decrementGrade();

    // Exception Classes
    class GradeTooHighException : public std::exception {
        const char* what() const noexcept override;
    };

    class GradeTooLowException : public std::exception {
        const char* what() const noexcept override;
    };

    // Overloaded Operator
    friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
};

#endif 
