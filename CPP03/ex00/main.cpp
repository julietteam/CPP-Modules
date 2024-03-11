/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:45:57 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/11 19:18:25 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap animal1("Guepard");
    ClapTrap animal2("Girafe");

    animal1.attack("Girafe");
    animal1.beRepaired(1);
    animal2.takeDamage(8);

    
    return (0);
}