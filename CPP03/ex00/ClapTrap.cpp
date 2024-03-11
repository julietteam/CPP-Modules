/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:25:54 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/11 19:13:37 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std:: string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) 
    : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
    std::cout << "ClapTrap copy constructor called." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) 
{
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap assignment operator called." << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " has no energy points left and can't attack." << std::endl;
        return;
    }
    else if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " is out of hit points and can't attack " << target << std::endl;
        return;
    }
    else
    {
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints == 0 || energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " can't take damage, it's already down!" << std::endl;
        return;
    }
    if (hitPoints > amount)
    {
        hitPoints = hitPoints - amount;
        std::cout << "ClapTrap " << name << " took " << amount << " points of damage !" << std::endl;
    }
    else
    {
        hitPoints = 0;
        std::cout << "ClapTrap " << name << " can't lose more points because he doesn't have any left." << std::endl;
    }
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " is dead !" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " can't be repaired due to no energy!" << std::endl;
        return;
    }
    if (hitPoints > 0)
    {
        hitPoints = hitPoints + amount;
        std::cout << "ClapTrap " << name << " repairs itself, regaining " << amount << " hit points!" << std::endl;
        energyPoints--;
    }
    else
        std::cout << "ClapTrap " << name << " can't be repaired, it's already down!" << std::endl;
}