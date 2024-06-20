/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:15:13 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/20 10:31:09 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}
Intern::Intern(const Intern &other)
{
    std::cout << "Intern copy constructor called" << std::endl; 
    *this = other;
}

Intern &Intern::operator=(const Intern &other)
{
    if (this == &other) 
        return (*this);
    else 
        return (*this);
}
    
Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}


AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    int i;
    std::string forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    AForm *form = NULL;
    
    for (i = 0; i < 3; i++)
    {
        if (formName == forms[i])
        {
            switch (i)
            {
                case (0):
                    form = new ShrubberyCreationForm(target);
                    break;
                case (1):
                    form = new RobotomyRequestForm(target);
                    break;
                case (2):
                    form = new PresidentialPardonForm(target);
                    break;
            }
            std::cout << "Intern creates " << formName << std::endl;
            return (form);
        }
    }
    std::cout << "Intern failed to create " << formName;
    std::cout << " because the form doesn't exist." << std::endl;
    return (NULL);
}