/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:33:49 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/13 19:19:49 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"


Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other.getType())
{
    std::cout << "Ice copy constructor called" << std::endl;
}


Ice &Ice::operator=(const Ice &other)
{
    if (this != &other)
    {
        AMateria::operator=(other);
        std::cout << "Ice assignment operator called" << std::endl;
    }
    return *this;
}

Ice:: ~Ice()
{
    std::cout << "Ice destructor called" << std::endl;
}

AMateria *Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName();
    std::cout << " *" << std::endl;
}