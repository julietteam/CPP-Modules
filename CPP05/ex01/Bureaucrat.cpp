/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:23:03 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/19 18:36:01 by juandrie         ###   ########.fr       */
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
	try
	{
		if (getGrade() < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (getGrade() > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what();
		this->grade = 1;
		std::cout << "Bureaucrat " << getName() << " is now set to default grade : 1" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what();
		this->grade = 150;
		std::cout << "Bureaucrat " << getName() << " is now set to default grade : 150" << std::endl;
	}
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

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch(Form::GradeTooLowException &e)
    {
        std::cout << this->getName() << " couldn't sign " << form.getName() << " because ";
        std::cout << e.what() << std::endl;
    }
    catch(Form::AlreadySignedException &e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because ";
		std::cout << e.what() << std::endl;
	}
    
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return (os);
}