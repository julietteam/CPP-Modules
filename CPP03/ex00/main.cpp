/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:45:57 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/11 22:54:49 by julietteand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapTrapA("Alpha");
    ClapTrap clapTrapB("Bravo");

    clapTrapA.attack("Bravo");

    clapTrapB.takeDamage(3);

    clapTrapB.beRepaired(5);

    for (int i = 0; i < 11; ++i)
    {
        clapTrapA.attack("Bravo");
    }

    clapTrapB.takeDamage(100);

    clapTrapB.beRepaired(1);

    clapTrapB.beRepaired(1);

    clapTrapA.beRepaired(10);

    ClapTrap clapTrapC = clapTrapA;
    clapTrapC.attack("Bravo");

    ClapTrap clapTrapD("Delta");
    clapTrapD = clapTrapB;
    clapTrapD.beRepaired(5);

    return 0;
}
