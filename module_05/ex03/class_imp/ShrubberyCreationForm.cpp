#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    std::cout << "ShrubberyCreationForm: Parametric constructor called" << std::endl;
    return ;
}

void ShrubberyCreationForm::executeAction() const
{
    std::ofstream file(target + "_shrubbery");
    if (!file)
    {
        std::cerr << "Error: Could not open file" << std::endl;
        return ;
    }
    file <<
        "      /\\\n"
        "     /**\\\n"
        "    /****\\\n"
        "   /******\\\n"
        "  /********\\\n"
        "      ||\n"
        "      ||\n";
    file.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm: Destructor called" << std::endl;
    return ;
}
