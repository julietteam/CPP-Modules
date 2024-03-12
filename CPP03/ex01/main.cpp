/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:45:57 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/12 10:57:12 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "Creating ClapTraps..." << std::endl;
    ClapTrap defaultClapTrap;
    ClapTrap namedClapTrap("Clappy");
    ClapTrap anotherClapTrap("Clapster");

    std::cout << "\nTesting ClapTrap behavior..." << std::endl;
    namedClapTrap.attack("TargetB");
    namedClapTrap.takeDamage(5);
    namedClapTrap.beRepaired(3);

    std::cout << "\nTesting ClapTrap energy depletion..." << std::endl;
    for (int i = 0; i < 15; i++)
    {
        defaultClapTrap.attack("TargetA");
    }

    std::cout << "\nTesting ClapTrap death..." << std::endl;
    anotherClapTrap.takeDamage(100);
    anotherClapTrap.attack("TargetC");
    anotherClapTrap.beRepaired(10);

    std::cout << "\nCreating ScavTraps..." << std::endl;
    ScavTrap defaultScavTrap;
    ScavTrap namedScavTrap("Scavvy");
    
    std::cout << "\nTesting ScavTrap behavior..." << std::endl;
    namedScavTrap.guardGate();
    namedScavTrap.attack("TargetC");
    namedScavTrap.takeDamage(30);
    namedScavTrap.beRepaired(20);

    std::cout << "\nTesting copy construction and assignment..." << std::endl;
    ScavTrap clonedScavTrap(namedScavTrap);
    ScavTrap assignedScavTrap = namedScavTrap;

    clonedScavTrap.attack("The air");
    assignedScavTrap.attack("The ground");
    
    std::cout << "\nEnd of tests, objects will now be destroyed." << std::endl;

    return 0;
}
