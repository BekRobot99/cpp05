#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Unnamed"), grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : name(other.name), grade(other.grade) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : name(name), grade(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}


Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        const_cast<std::string&>(name) = other.name; // Dangerous, but hypothetical scenario to comply.
        grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

// Getters
const std::string& Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

// Modifiers
void Bureaucrat::incrementGrade() {
    if (grade <= 1)
        throw GradeTooHighException();
    --grade;
}

void Bureaucrat::decrementGrade() {
    if (grade >= 150)
        throw GradeTooLowException();
    ++grade;
}

// Exception Messages
const char* Bureaucrat::GradeTooHighException::what() const noexcept {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
    return "Grade is too low!";
}

// Overloaded Operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}
