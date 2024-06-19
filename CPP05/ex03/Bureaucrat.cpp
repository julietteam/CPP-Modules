/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:23:03 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/19 19:55:04 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Unnamed"), grade(150)
{
    std::cout << "Bureaucrat default constructor called for " << getName() << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade)
{
    std::cout << "Bureaucrat assign constructor called for " << getName() << std::endl;
	if (getGrade() < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (getGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
    else
        this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
    std::cout << "Bureaucrat copy constructor called for " << getName() << std::endl;
}


Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        this->grade = other.grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called for " << getName() << std::endl;
}

const std::string &Bureaucrat::getName() const
{
    return (name);
}

int Bureaucrat::getGrade() const
{
    return (grade);
}
void Bureaucrat::incrementGrade()
{
    try
    {
        if (grade <= 1)
            throw GradeTooHighException();
        else
            --grade; 
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what();
    } 
}
void Bureaucrat::decrementGrade()
{
   try
    {
        if (grade >= 150)
            throw GradeTooLowException();
        else
            ++grade;
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what();
    }
}

void Bureaucrat::signForm(AForm &aForm)
{
    try
    {
        aForm.beSigned(*this);
        std::cout << this->getName() << " signed " << aForm.getName() << std::endl;
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cout << this->getName() << " couldn't sign " << aForm.getName() << " because ";
        std::cout << e.what() << std::endl;
    }
    catch(AForm::AlreadySignedException &e)
	{
		std::cout << this->getName() << " couldn't sign " << aForm.getName() << " because ";
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &aForm)
{
    try
    {
        aForm.execute(*this);
        std::cout << this->name << " executed " << aForm.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->name << " couldn't execute " << aForm.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return (os);
}