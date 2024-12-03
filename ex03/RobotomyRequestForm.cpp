#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45, "DefaultTarget") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45, target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::action() const {
    srand(time(0));
    if (rand() % 2 == 0)
        std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy of " << getTarget() << " failed!" << std::endl;
}
