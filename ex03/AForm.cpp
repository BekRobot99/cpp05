#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : _name("DefaultForm"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150), _target("DefaultTarget") {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute, const std::string& target)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _target(target) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute),
      _target(other._target) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const { return _name; }
const std::string& AForm::getTarget() const { return _target; }
bool AForm::isSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const {
    validateExecution(executor);
    action();
}

void AForm::validateExecution(const Bureaucrat& executor) const {
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
}

// Overload of the insertion operator
std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form: " << form.getName()
       << ", Target: " << form.getTarget()
       << ", Signed: " << (form.isSigned() ? "Yes" : "No")
       << ", Grade to Sign: " << form.getGradeToSign()
       << ", Grade to Execute: " << form.getGradeToExecute();
    return os;
}
