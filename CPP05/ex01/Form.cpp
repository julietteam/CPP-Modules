/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:20:03 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/06 16:12:56 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default Form"), isSigned(false), gradeRequiredToSign(150), gradeRequiredToExecute(150)
{
}

Form::Form(const std::string name, int gradeToSign, int gradeToExecute)
: name(name), isSigned(false), gradeRequiredToSign(gradeToSign), gradeRequiredToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
         
}
Form::Form(const Form &other) 
: name(other.name), isSigned(other.isSigned), gradeRequiredToSign(other.gradeRequiredToSign), gradeRequiredToExecute(other.gradeRequiredToExecute)
{
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
}

const std::string &Form::getName() const
{
    return (name);
}

bool Form::getIsSigned() const
{
    return (isSigned);
}

int Form::getGradeRequiredToSign() const
{
    return (gradeRequiredToSign);
}

int Form::getGradeRequiredToExecute() const
{
    return (gradeRequiredToExecute);
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > getGradeRequiredToSign())
        throw GradeTooLowException();
    isSigned = true;
    
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form " << form.getName() << " is " << (form.getIsSigned() ? "signed" : "not signed")
       << ", grade required to sign: " << form.getGradeRequiredToSign() 
       << ", grade required to execute: " << form.getGradeRequiredToExecute() << std::endl;
    
    return (os);
}