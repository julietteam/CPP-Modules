/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:42:31 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/12 19:12:48 by julietteand      ###   ########.fr       */
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
    DiamondTrap dt2("DiamonHuman");
    dt2.whoAmI();
    
    std::cout << "\nTesting assignment operator...\n" << std::endl;
    DiamondTrap dt3 ("DiamondGirl");
    dt1 = dt3;
    dt1.whoAmI();

    std::cout << "\nTesting destruction...\n" << std::endl;

    return 0;
}
