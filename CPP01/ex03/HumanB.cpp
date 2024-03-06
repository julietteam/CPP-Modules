/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:52:59 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/06 11:53:28 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanA.hpp"
#include "Weapon.hpp"
#include "HumanB.hpp"


HumanB::HumanB(const std::string name) : name(name), weapon(NULL)
{
}

void HumanB::setWeapon(Weapon &newWeapon)
{
    weapon = &newWeapon;
}
void HumanB::attack() const
{
    if (weapon)
    {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    }
    else
    {
        std::cout << name << " has no weapon" << std::endl;
    }
}