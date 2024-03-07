/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:23:03 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/07 13:26:26 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./HarlFilter [LEVEL]" << std::endl;
        return (1);
    }
    
    Harl harl;
    harl.complain(argv[1]);
    
    return (0);
}