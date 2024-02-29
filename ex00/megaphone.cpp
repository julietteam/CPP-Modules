/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:31:46 by juandrie          #+#    #+#             */
/*   Updated: 2024/02/29 17:08:23 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        for (size_t j = 0; j < arg.length(); ++j)
        {
            std::cout << static_cast <char> (toupper(arg[j]));
        }
        std::cout << ' ';
    }
    std::cout << std::endl;
    return (0);
    
}