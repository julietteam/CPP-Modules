/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:35:00 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/28 18:20:52 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <values>" << std::endl;
        return (1);
    }
    Rpn calc;
    std::istringstream iss(argv[1]);
    std::string token;
    
    try
    {
        while (iss >> token)
        {
            if (calc.isOperator(token))
                calc.performOperation(token);
            else
            {
                double value;
                std::istringstream tokenStream(token);
                if (!(tokenStream >> value))
                {
                    std::cout << "Error" << std::endl;
                    return (1);
                }
                calc.push(value);
            }
        }
        std::cout << calc.getResult() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return (1);
    }
    return (0);
}