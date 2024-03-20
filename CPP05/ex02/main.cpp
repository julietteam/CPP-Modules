/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:31:39 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/20 18:43:19 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"


int main()
{
    Bureaucrat bob("Bob", 1);
    Bureaucrat joe("Joe", 150);

    ShrubberyCreationForm shrubForm("home");
    RobotomyRequestForm robotForm("Bob");
    PresidentialPardonForm pardonForm("Joe");

    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Tentative de signature et exécution par Bob" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    try
    {
        bob.signForm(shrubForm);
        bob.executeForm(shrubForm);
    } 
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try 
    {
        bob.signForm(robotForm);
        bob.executeForm(robotForm);
    } 
    catch (std::exception& e) 
    {
        std::cout << e.what() << std::endl;
    }

    try 
    {
        bob.signForm(pardonForm);
        bob.executeForm(pardonForm);
    } 
    catch (std::exception& e) 
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Tentative de signature et exécution par Joe" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    try
    {
        joe.signForm(shrubForm);
        joe.executeForm(shrubForm);
    } 
    catch (std::exception& e) 
    {
        std::cout << e.what() << std::endl;
    }

    try 
    {
        joe.signForm(robotForm);
        joe.executeForm(robotForm);
    } 
    catch (std::exception& e) 
    {
        std::cout << e.what() << std::endl;
    }

    try 
    {
        joe.signForm(pardonForm);
        joe.executeForm(pardonForm);
    } 
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}