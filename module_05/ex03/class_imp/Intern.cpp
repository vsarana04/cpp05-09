#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
    std::cout << "Intern copy constructor called" << std::endl;
    *this = other;
}

Intern &Intern::operator=(const Intern &other)
{
    std::cout << "Intern assignment operator called" << std::endl;
    if (this != &other)
    {
        
    }
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

AForm *Intern::makeForm(const std::string ame, const std::string target)
{
    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *(*formCreators[3])(std::string) = {&ShrubberyCreationForm::create, &RobotomyRequestForm::create, &PresidentialPardonForm::create};

    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            return formCreators[i](target);
        }
    }
    throw FormNotFoundException();
}


AForm* Intern::makeForm(const std::string &name, const std::string &target)
{
    std::string names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (*formCreators[])(const std::string&) ={ &createShrubbery, &createRobotomy, &createPardon};

    for (int i = 0; i < 3; i++)
    {
        if (name == names[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return (formCreators[i](target));
        }
    }

    std::cout << "Intern couldn't find the form: " << name << std::endl;
    return (NULL);
}
