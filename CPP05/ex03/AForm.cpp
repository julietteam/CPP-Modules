/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:20:03 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/20 15:29:13 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute)
: name(name), isSigned(false), gradeRequiredToSign(gradeToSign), gradeRequiredToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
         
}
AForm::AForm(const AForm &other) 
: name(other.name), isSigned(other.isSigned), gradeRequiredToSign(other.gradeRequiredToSign), gradeRequiredToExecute(other.gradeRequiredToExecute)
{
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return (*this);
}


AForm::~AForm()
{
}

const std::string &AForm::getName() const
{
    return (name);
}

bool AForm::getIsSigned() const
{
    return (isSigned);
}

int AForm::getGradeRequiredToSign() const
{
    return (gradeRequiredToSign);
}

int AForm::getGradeRequiredToExecute() const
{
    return (gradeRequiredToExecute);
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > getGradeRequiredToSign())
        throw GradeTooLowException();
    isSigned = true;
    
}

std::ostream &operator<<(std::ostream &os, const AForm &aForm)
{
    os << "Form " << aForm.getName() << " is " << (aForm.getIsSigned() ? "signed" : "not signed")
       << ", grade required to sign: " << aForm.getGradeRequiredToSign() 
       << ", grade required to execute: " << aForm.getGradeRequiredToExecute() << std::endl;
    
    return (os);
}