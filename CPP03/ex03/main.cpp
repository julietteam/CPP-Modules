/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:42:31 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/12 15:06:37 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    std::cout << "Creating DiamondTrap instances...\n" << std::endl;
    
    DiamondTrap dt1("DiamondBoy");
    dt1.whoAmI();
    dt1.attack("EnemyBot");
    dt1.takeDamage(30);
    dt1.beRepaired(20);
    dt1.guardGate();
    dt1.highFivesGuys();
    
    std::cout << "\nTesting copy constructor...\n" << std::endl;
    DiamondTrap dt2(dt1);
    dt2.whoAmI();
    
    std::cout << "\nTesting assignment operator...\n" << std::endl;
    DiamondTrap dt3 ("DiamondGirl");
    dt3 = dt1;
    dt3.whoAmI();

    std::cout << "\nTesting destruction...\n" << std::endl;

    return 0;
}
