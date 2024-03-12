/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:27:21 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/12 15:02:14 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
: ClapTrap("Default_clap_name"), ScavTrap("Default"), FragTrap("Default"), _name("Default")
{
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap default constructor called." << std::endl; 
}

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) 
{
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap " << _name << " was created." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name) 
{
    std::cout << "DiamondTrap copy constructor called." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    { 
        ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        _name = other._name;
    }
    std::cout << "DiamondTrap assignment operator called." << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << _name << " was destroyed." << std::endl;
}

void DiamondTrap::attack(const std::string  &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am " << _name << " and my ClapTrap name is " << ClapTrap::name << "." << std::endl;
}
