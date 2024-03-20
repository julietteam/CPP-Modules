/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:39:01 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/20 17:05:08 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
: AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (!getIsSigned())
        throw std::runtime_error("Form isn't signed.");

    if (executor.getGrade() > getGradeRequiredToExecute())
        throw GradeTooLowException();

    std::ofstream file((target + "_shrubbery").c_str());
    if (file.is_open())
    {
        file << "    /\\    " << std::endl;
        file << "   /  \\   " << std::endl;
        file << "  /    \\  " << std::endl;
        file << " /      \\ " << std::endl;
        file << "/________\\" << std::endl;
        file << "    ||||   " << std::endl;
        file << "    ||||   " << std::endl;
    }
    else
        throw std::runtime_error("Cannot open file.");
}