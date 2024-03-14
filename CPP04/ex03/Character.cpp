/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:17:31 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/14 17:33:43 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "ICharacter.hpp"

Character::Character(std::string const &name) : name(name)
{
    for (int i = 0; i < 4; ++i)
        inventory[i] = NULL;
    std::cout << "Character constructor called" << std::endl;
}

Character::Character(Character const &other) : name(other.name)
{
    for (int i = 0; i < 4; ++i)
    {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
    std::cout << "Character copy constructor called" << std::endl;
}

Character &Character::operator=(Character const &other)
{
    if (this != &other)
    {
        name = other.name;
        for (int i = 0; i < 4; ++i)
        {
            delete inventory[i];
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
        std::cout << "Character assignment operator called" << std::endl;
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; ++i)
    {
        delete inventory[i];
        inventory[i] = NULL;
    }
    std::cout << "Character destructor called" << std::endl;
}

std::string const &Character::getName() const
{
    return (name);
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; ++i)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
    {
        inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
        inventory[idx]->use(target);
}
