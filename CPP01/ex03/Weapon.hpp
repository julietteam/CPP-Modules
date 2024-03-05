/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:39:17 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/05 18:56:10 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

class Weapon
{
private:
    std::string type;
    
public:
    Weapon(const std::string &type);

    const std::string &getType() const {
        return type;
    }
    void setType(const std::string &newType){ 
        type = newType;
    }
    
};


#endif