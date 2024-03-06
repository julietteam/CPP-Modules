/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:09:55 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/06 12:49:32 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filename.hpp"

int main(int ac, char **av)
{
    std:: string s1;
    std:: string s2;

    if (ac != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <string to replace> <string to replace with>" << std::endl;
        return 1;
    }
}