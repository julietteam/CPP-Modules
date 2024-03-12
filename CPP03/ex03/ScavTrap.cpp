/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:19:18 by julietteand       #+#    #+#             */
/*   Updated: 2024/03/12 13:19:02 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap default constructor called." << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    ClapTrap::operator=(other);
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called for " << name << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is guarding the gate." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " has no energy points left and can't attack." << std::endl;
        return;
    }
    else if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " is out of hit points, he is dead and can't attack " << target << std::endl;
        return;
    }
    else
    {
        std::cout << "ScavTrap " << name << " attacks ";
        std::cout << target << ", causing " << attackDamage;
        std::cout << " points of damage!" << std::endl;
        energyPoints--;
    }
}

