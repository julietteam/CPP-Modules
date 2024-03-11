/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:25:54 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/11 23:38:44 by julietteand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): Name(""), HitPoints(100), EnergyPoints(50), AttackDamage(20)
{
    std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std:: string Name) : Name(Name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << "ClapTrap constructor called for " << this->Name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) 
    : Name(other.Name), HitPoints(other.HitPoints), EnergyPoints(other.EnergyPoints), AttackDamage(other.AttackDamage)
{
    std::cout << "ClapTrap copy constructor called." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) 
{
    if (this != &other)
    {
        Name = other.Name;
        HitPoints = other.HitPoints;
        EnergyPoints = other.EnergyPoints;
        AttackDamage = other.AttackDamage;
    }
    std::cout << "ClapTrap assignment operator called." << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called for " << this->Name << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (EnergyPoints == 0)
    {
        std::cout << "ClapTrap " << Name << " has no energy points left and can't attack." << std::endl;
        return;
    }
    else if (HitPoints == 0)
    {
        std::cout << "ClapTrap " << Name << " is out of hit points, he is dead and can't attack " << target << std::endl;
        return;
    }
    else
    {
        std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
        EnergyPoints--;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (HitPoints == 0)
    {
        std::cout << "ClapTrap " << Name << " can't lose points, he is dead !" << std::endl;
        return;
    }
    if (EnergyPoints == 0)
    {
        std::cout << "ClapTrap " << Name << " can't lose points, he has no energy points left !" << std::endl;
    }
    if (HitPoints > amount)
    {
        HitPoints = HitPoints - amount;
        std::cout << "ClapTrap " << Name << " took " << amount << " points of damage !" << std::endl;
    }
    else
    {
        HitPoints = 0;
        std::cout << "ClapTrap " << Name << " can't lose points, he is dead." << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (EnergyPoints == 0)
    {
        std::cout << "ClapTrap " << Name << " can't be repaired due to no energy!" << std::endl;
        return;
    }
    if (HitPoints == 0)
    {
        std::cout << "ClapTrap " << Name << " can't be repaired, he is dead !" << std::endl;
        return; 
    }
    if (HitPoints > 0)
    {
        HitPoints = HitPoints + amount;
        std::cout << "ClapTrap " << Name << " repairs itself, regaining " << amount << " hit points!" << std::endl;
        EnergyPoints--;
    }
}