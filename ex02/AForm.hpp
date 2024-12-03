#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

// Forward declaration of Bureaucrat
class Bureaucrat;

class AForm {
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

    class FormNotSignedException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Form is not signed!";
        }
    };

    AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute, const std::string& target);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    // Member functions
    const std::string& getName() const;
    const std::string& getTarget() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat& bureaucrat);
    void execute(const Bureaucrat& executor) const;

    virtual void action() const = 0;

protected:
    void validateExecution(const Bureaucrat& executor) const;

private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
    const std::string _target;
};

// Overload of the insertion operator
std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
