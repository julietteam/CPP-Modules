/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:50:14 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/04 12:20:35 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string command;
    
    while (true)
    {
        std:: cout << "Enter a command (ADD, SEARCH or EXIT):" << std::endl;
        std:: cin >> command;
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