/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:05:38 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/14 11:09:44 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N = 5;
    int i = 0;
    std:: string name = "Zombie";
    Zombie  *horde = zombieHorde(N, "Zombie");

    while (i < N)
    {
        horde[i].announce();
        i++;
    }
    delete []horde;
    return (0);
}