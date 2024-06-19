/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:31:39 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/19 19:49:32 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"


int main()
{
    /*// tester des valeurs plus elevees que 145, 72, 25*/
    // try
    // {
    //     Bureaucrat bob("Bob", -5);
    // }
    // catch(const std::exception& e)
    // {
    //     std::cout << e.what() << std::endl;
    // }

    try
    {
        Bureaucrat bob("Bob", 1);
        Bureaucrat joe("Joe", 150);
        ShrubberyCreationForm shrubForm("home");
        RobotomyRequestForm robotForm("Bob");
        PresidentialPardonForm pardonForm("Joe");

        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "Tentative de signature et exécution par Bob" << std::endl;
        std::cout << "-------------------------------------------" << std::endl;
        
        bob.signForm(shrubForm);
        bob.executeForm(shrubForm);
        
        bob.signForm(robotForm);
        bob.executeForm(robotForm);
        bob.signForm(pardonForm);
        bob.executeForm(pardonForm);
        
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "Tentative de signature et exécution par Joe" << std::endl;
        std::cout << "-------------------------------------------" << std::endl;
    
        joe.signForm(shrubForm);
        joe.executeForm(shrubForm);
    
        joe.signForm(robotForm);
        joe.executeForm(robotForm);
        
        joe.signForm(pardonForm);
        joe.executeForm(pardonForm);
    }
    
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    return (0);
}