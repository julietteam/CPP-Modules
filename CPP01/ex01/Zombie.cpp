/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:54:35 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/05 14:39:49 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}
Zombie::Zombie(std::string name) : name(name)
{
    std::cout << name << " has been created" << std::endl;
}
 
Zombie::~Zombie()
{
    std::cout << name << " has been deleted" << std::endl;
}

void    Zombie::announce(void) const
{
    std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}