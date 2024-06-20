/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:31:39 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/20 10:40:07 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"


int main()
{
    Intern intern;
    AForm *aForm;
    Bureaucrat Chief("Juliette", 2);

    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Test avec le formulaire RobotomyRequestForm" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    aForm = intern.makeForm("RobotomyRequestForm", "Bender");
    if (aForm)
    {
        std::cout << "Successfully created form: " << aForm->getName() << std::endl;
        Chief.signForm(*aForm);
        Chief.executeForm(*aForm);
        delete aForm;
    }
    
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "Test avec le formulaire PresidentialPardonForm" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    aForm = intern.makeForm("PresidentialPardonForm", "Leela");
    if (aForm)
    {
        std::cout << "Successfully created form: " << aForm->getName() << std::endl;
        Chief.signForm(*aForm);
        Chief.executeForm(*aForm);
        delete aForm;
    }
    
    
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "Test avec le formulaire ShrubberyCreationForm" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    aForm = intern.makeForm("ShrubberyCreationForm", "Home");
    if (aForm)
    {
        std::cout << "Successfully created form: " << aForm->getName() << std::endl;
        Chief.signForm(*aForm);
        Chief.executeForm(*aForm);
        delete aForm;
    }

    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "Test avec un formulaire inconnu" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    aForm = intern.makeForm("unknown form", "Nowhere");
    if (!aForm)
    {
        std::cout << "Failed to create form: unknown form" << std::endl;
    }
    else
    {
        Chief.signForm(*aForm);
        Chief.executeForm(*aForm);
        delete aForm;
    }

    return 0;
}