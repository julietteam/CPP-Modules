/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:31:14 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/06 18:04:13 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Default")
{
    std::srand(std::time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
: AForm("RobotomyRequestForm", 72, 45), target(target)
{
    std::srand(std::time(0));
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target(other.target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (!getIsSigned())
        throw std::runtime_error("Form isn't signed.");

    if (executor.getGrade() > getGradeRequiredToExecute())
        throw GradeTooLowException();

    std::cout << "* intensive drilling noise *" << std::endl;

    if (std::rand() % 2)
        std::cout << target << " has been successfully robotomised." << std::endl;
    else
        std::cout << "Robotomy of " << target << " failed" << std::endl;
}