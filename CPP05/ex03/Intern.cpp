/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:15:13 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/20 18:52:50 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


Intern::Intern()
{
}
Intern::Intern(const Intern &other)
{
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