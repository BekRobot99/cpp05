#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137, "DefaultTarget") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137, target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::action() const {
    std::ofstream file(getTarget() + "_shrubbery");
    if (!file.is_open())
        throw std::ios_base::failure("Failed to open file.");
    file << "ASCII Tree" << std::endl;
    file.close();
}
