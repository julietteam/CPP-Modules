/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:15:07 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/18 11:22:52 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : type("AMateria")
{
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type)
{
    std::cout << "AMateria constructor called" << std::endl;
}
AMateria::AMateria(const AMateria &other) : type(other.type)
{
    std::cout << "AMateria copy constructor called" << std::endl;
}
AMateria &AMateria::operator=(const AMateria &other)
{
    if (this != &other)
    {
        type = other.type;
        std::cout << "AMateria assignment operator called" << std::endl;
    }
    return (*this);
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called" << std::endl;
}

void AMateria::use(ICharacter &target)
{
   std::cout << "Using AMateria on " << target.getName() << std::endl; 
}

std::string const &AMateria::getType() const
{
    return (type);
}