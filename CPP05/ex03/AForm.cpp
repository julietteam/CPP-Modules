/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:20:03 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/19 19:53:02 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default Form"), isSigned(false), gradeRequiredToSign(150), gradeRequiredToExecute(150)
{
    std::cout << "AForm default constructor called for " << getName() << std::endl;
}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute)
: name(name), isSigned(false), gradeRequiredToSign(gradeToSign), gradeRequiredToExecute(gradeToExecute)
{
    std::cout << "AForm assign constructor called for " << getName() << std::endl;
    try
    {
        if (this->gradeRequiredToSign < 1 || this->gradeRequiredToExecute < 1)
            throw AForm::GradeTooHighException();
        else if (this->gradeRequiredToSign > 150 || this->gradeRequiredToExecute > 150)
            throw AForm::GradeTooLowException();
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(AForm::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
}
AForm::AForm(const AForm &other) 
: name(other.name), isSigned(other.isSigned), gradeRequiredToSign(other.gradeRequiredToSign), gradeRequiredToExecute(other.gradeRequiredToExecute)
{
    std::cout << "AForm copy constructor called for " << getName() << std::endl;
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
    std::cout << "AForm destructor called for " << getName() << std::endl;
}

const std::string &AForm::getName() const
{
    return (this->name);
}

bool AForm::getIsSigned() const
{
    return (this->isSigned);
}

int AForm::getGradeRequiredToSign() const
{
    return (this->gradeRequiredToSign);
}

int AForm::getGradeRequiredToExecute() const
{
    return (this->gradeRequiredToExecute);
}

void AForm::beSigned(const Bureaucrat &b)
{
   if (b.getGrade() <= this->getGradeRequiredToSign())
    {
        if (this->isSigned)
            throw AForm::AlreadySignedException();
        else
            this->isSigned = true;
    }
    else
    {
        throw AForm::GradeTooLowException();
    }
}

std::ostream &operator<<(std::ostream &os, const AForm &aForm)
{
    os << "Form name = " << aForm.getName() << std::endl;
    if (aForm.getIsSigned())
        os << "This form is signed" << std::endl;
    else
        os << "This form is not signed" << std::endl;
    os << "Grade required to sign the form: " << aForm.getGradeRequiredToSign() << std::endl;
    os << "Grade required to execute the form: " << aForm.getGradeRequiredToExecute() << std::endl;
    
    return (os);
}