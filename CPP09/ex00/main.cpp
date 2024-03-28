/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:26:47 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/28 12:36:54 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cout << "Usage: " << argv[0] << " <CSV file name>" << std::endl;
        return (1);
    }

    std::map<std::string, float> historicalData;
    if (!BitcoinExchange::loadDataFromFile(argv[1], historicalData))
    {
        std::cout << "Error loading data from file." << std::endl;
        return (1);
    }

    if (!BitcoinExchange::processInputFile(argv[2], historicalData))
    {
        std::cout << "Error processing input file: " << argv[2] << std::endl;
        return 1;
    }

    return (0);
}