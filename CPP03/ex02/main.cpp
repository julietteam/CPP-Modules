/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:24:24 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/12 12:50:30 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap ct("Clappy");
    ct.attack("un ennemi");
    ct.takeDamage(90);
    ct.beRepaired(50);
    ct.takeDamage(100);
    ct.beRepaired(20);

    ScavTrap st("Scavvy");
    st.attack("Clappy");
    st.takeDamage(90);
    st.beRepaired(50);
    st.guardGate();

    FragTrap ft("Fraggy");
    ft.attack("Scavvy");
    ft.highFivesGuys();
    ft.takeDamage(90);
    ft.beRepaired(50);

    
    FragTrap tempFt("TempFraggy");
    tempFt.attack("un ennemi temporaire");
    
    FragTrap assignedFt;
    assignedFt = ft;

    assignedFt.attack("un ennemi assigné");
    assignedFt.highFivesGuys();

    
    FragTrap copiedFt(ft);
    copiedFt.attack("un ennemi copié");
    copiedFt.highFivesGuys();

    std::cout << "Fin des tests." << std::endl;
    return 0;
}
