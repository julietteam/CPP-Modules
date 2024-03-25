/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:55:51 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/25 18:55:48 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    try
    {
        Array<int> intArray(5);
        for (unsigned int i = 0; i < intArray.size(); ++i)
        {
            intArray[i] = i;
        }
        
        for (unsigned int i = 0; i < intArray.size(); ++i)
        {
            std::cout << intArray[i] << std::endl;
        }
        std::cout << intArray[5] << std::endl;
    } 
    catch (const std::exception& e)
    {
        std::cout << "An exception was caught: " << e.what() << std::endl;
    }

    return 0;
}