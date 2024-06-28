/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:26:47 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/28 18:03:54 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        try
        {
            BitcoinExchange btc;
            btc.setDataBase();
            std::map<std::string, float> historicalData;
            btc.processInputFile(argv[1], historicalData);
        }
        catch(const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            return (1);
        }
    }
    else 
    {
        std::cout << "Error: could not open file." << std::endl;
    }
    return (0);
}