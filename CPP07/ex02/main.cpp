/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:55:51 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/25 16:16:28 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    
    std::cout << "-----Emtpy array test : --------------" << std::endl;
    Array<int> emptyarr;
    
    std::cout << "-----Tests non-const objects : " << std::endl;

    Array<int> tab(3);
    for (unsigned int i = 0; i < 3; i++)
	{
		tab[i] = 4;	
		std::cout << tab[i] << std::endl;
	}
    std::cout << "------Index test : -------------------" << std::endl;
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
        std::cout << "found index successfully: " << intArray[3] << std::endl;
    } 
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "------Modify data : -------------------" << std::endl;
    tab[0] = 17;
	tab[1] = 18;
	tab[2] = 20;

    Array<int> tab2(tab);
	for (unsigned int i = 0; i < 3; i++)
		std::cout << tab2[i] << std::endl;

    Array<int> tab3(4);
	tab3 = tab2;
	for (unsigned int i = 0; i < 3; i++)
		std::cout << tab3[i] << std::endl;
    
    return (0);
}

