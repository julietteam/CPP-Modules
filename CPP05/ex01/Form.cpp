/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:20:03 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/19 18:39:34 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default Form"), isSigned(false), gradeRequiredToSign(150), gradeRequiredToExecute(150)
{
    std::cout << "Form default constructor called for " << getName() << std::endl;
}

Form::Form(const std::string name, int gradeToSign, int gradeToExecute)
: name(name), isSigned(false), gradeRequiredToSign(gradeToSign), gradeRequiredToExecute(gradeToExecute)
{
    std::cout << "Form assign constructor called for " << getName() << std::endl;
    try
    {
        if (this->gradeRequiredToSign < 1 || this->gradeRequiredToExecute < 1)
            throw Form::GradeTooHighException();
        else if (this->gradeRequiredToSign > 150 || this->gradeRequiredToExecute > 150)
            throw Form::GradeTooLowException();
    }
    catch(Form::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(Form::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
}
Form::Form(const Form &other) 
: name(other.name), isSigned(other.isSigned), gradeRequiredToSign(other.gradeRequiredToSign), gradeRequiredToExecute(other.gradeRequiredToExecute)
{
    std::cout << "Form copy constructor called for " << getName() << std::endl;
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return (*this);
}

Form::~Form()
{
    std::cout << "Form destructor called for " << getName() << std::endl;
}

const std::string &Form::getName() const
{
    return (this->name);
}

bool Form::getIsSigned() const
{
    return (this->isSigned);
}

int Form::getGradeRequiredToSign() const
{
    return (this->gradeRequiredToSign);
}

int Form::getGradeRequiredToExecute() const
{
    return (this->gradeRequiredToExecute);
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() <= this->getGradeRequiredToSign())
    {
        if (this->isSigned)
            throw Form::AlreadySignedException();
        else
            this->isSigned = true;
    }
    else
    {
        throw Form::GradeTooLowException();
    }
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form name = " << form.getName() << std::endl;
    if (form.getIsSigned())
        os << "This form is signed" << std::endl;
    else
        os << "This form is not signed" << std::endl;
    os << "Grade required to sign the form: " << form.getGradeRequiredToSign() << std::endl;
    os << "Grade required to execute the form: " << form.getGradeRequiredToExecute() << std::endl;
    
    return (os);
}