/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:50:14 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/05 18:04:21 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <limits>

int main()
{
    PhoneBook phonebook;
    std::string command;
    
    while (true)
    {
        std:: cout << "Enter a command (ADD, SEARCH or EXIT):" << std::endl;
        if (!(std::cin >> command))
        {
            if (std::cin.eof())
            {
                std::cout << "EOF detected. Exiting program." << std::endl;
                break;
            }
            else
            {
                std::cerr << "Input error. Please try again." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
        }
        if (command == "ADD")
            phonebook.addContact();
        else if (command == "SEARCH")
            phonebook.searchContact();
        else if (command == "EXIT")
            break;
        else 
            std::cout << "Command not recognized" << std::endl;
    }
}