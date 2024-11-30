#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form {
public:
    // Nested exception classes
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Form grade is too high!";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Form grade is too low!";
        }
    };

    Form();
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    // Member functions
    const std::string& getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(const Bureaucrat& bureaucrat);

private:
    const std::string name;
    bool _isSigned;
    const int gradeToSign;
    const int gradeToExecute;

    void validateGrade(int grade) const;
};

// Overload of the insertion operator
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif // FORM_HPP
