/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:45:57 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/11 23:43:38 by julietteand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    // Test du constructeur par défaut de ClapTrap
    ClapTrap clapTrap;
    clapTrap.attack("TargetA");

    // Test du constructeur avec nom de ClapTrap
    ClapTrap namedClapTrap("Clappy");
    namedClapTrap.attack("TargetB");

    // Test du constructeur par défaut de ScavTrap
    ScavTrap scavTrap;
    scavTrap.guardGate();

    // Test du constructeur avec nom de ScavTrap
    ScavTrap namedScavTrap("Scavvy");
    namedScavTrap.guardGate();
    namedScavTrap.attack("TargetC");

    // Test de prise de dégâts et de réparation
    namedScavTrap.takeDamage(30);
    namedScavTrap.beRepaired(20);

    // Vérifier la chaîne de construction/destruction en sortant de la portée
    {
        ScavTrap tempScavTrap("TempScavvy");
        tempScavTrap.attack("TargetD");
    } // tempScavTrap sera détruit ici

    std::cout << "Fin du main, destruction des autres objets." << std::endl;
    
    return 0;
}

