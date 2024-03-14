/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:45:22 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/14 18:23:24 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


FragTrap::FragTrap()
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap default constructor called." << std::endl;
}


FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap constructor called for " << name << std::endl; 
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called for " << name << std::endl; 
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    ClapTrap::operator=(other);
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called for " << name << std::endl; 
}

void FragTrap::attack(const std::string &target)
{
    if (energyPoints == 0)
    {
        std::cout << "FragTrap " << name << " has no energy points left and can't attack." << std::endl;
        return;
    }
    else if (hitPoints == 0)
    {
        std::cout << "FragTrap " << name << " is out of hit points, he is dead and can't attack " << target << std::endl;
        return;
    }
    else
    {
        std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    }
}
void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap requests a high five !" << std::endl;
}