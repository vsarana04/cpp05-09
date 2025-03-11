#include "../class/Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
    if (this->grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Parametric constructor called" << std::endl;
    return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    *this = other;
    std::cout << "Copy constructor called" << std::endl;
    return ;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        this->grade = other.grade;
    }
    std::cout << "Assignation operator called" << std::endl;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

std::string Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

void Bureaucrat::incrementGrade()
{
    this->grade--;
    if (this->grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    return ;
}

void Bureaucrat::decrementGrade()
{
    this->grade++;
    if (this->grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    return ;
}

void Bureaucrat::signForm(Form &form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->getName() << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
    }
    
}


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj)
{
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return (out);
}