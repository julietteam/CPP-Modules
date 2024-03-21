/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:33:25 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/21 18:37:35 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main()
{
    std::cout << "------------------" << std::endl;
    std::cout << "Test entier" << std::endl;
    std::cout << "------------------" << std::endl;
    ScalarConverter::convert("65");
    
    std::cout << "------------------" << std::endl;
    std::cout << "Test float" << std::endl;
    std::cout << "------------------" << std::endl;
    ScalarConverter::convert("42.0f");

    std::cout << "----------------------" << std::endl;
    std::cout << "Test valeurs speciales" << std::endl;
    std::cout << "----------------------" << std::endl;
    ScalarConverter::convert("nan");

    std::cout << "------------------" << std::endl;
    std::cout << "Test caractere" << std::endl;
    std::cout << "------------------" << std::endl;
    ScalarConverter::convert("a");

    return (0);
}

// int main(int argc, char** argv)
// {
//     if (argc != 2)
//     {
//         std::cerr << "Usage: " << argv[0] << " <value_to_convert>" << std::endl;
//         return 1;
//     }

//     std::string input = argv[1];

//     // Affiche les différents types de conversions basées sur l'entrée
//     ScalarConverter::convert(input);

//     return 0;
// }
