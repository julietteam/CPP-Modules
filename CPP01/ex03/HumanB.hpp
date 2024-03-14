/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:53:54 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/14 11:12:24 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"
#include "HumanA.hpp"

class HumanB
{
private:
    std::string name;
    Weapon      *weapon;
    
public:
    HumanB(std::string name);
    
    void setWeapon(Weapon &newWeapon);
    
    void attack() const;
};

#endif