/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:02:38 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/05 14:30:22 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream> 

std::string to_string(int number)
{
    std::ostringstream ss;
    ss << number;
    return ss.str();
}

Zombie* zombieHorde( int N, std::string name )
{
   int  i = 0;
   Zombie *horde = new Zombie[N];
   
   while (i < N)
   {
        new (horde + i) Zombie(name + " " + to_string(i + 1));
        ++i;
   }
   return (horde);
}