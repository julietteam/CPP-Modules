/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:40:28 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/06 11:24:55 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : type(type)
{
} 
const std::string& Weapon::getType() const
{
    return type;
}

void Weapon::setType(const std::string &newType)
{ 
        type = newType;
}