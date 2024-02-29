/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:20:28 by juandrie          #+#    #+#             */
/*   Updated: 2024/02/29 18:54:19 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <limits>
#include <iomanip> // Pour std::setw et std::setfill

PhoneBook::PhoneBook() : current_contact(0) {
}


void PhoneBook::addContact()
{
    if (current_contact >= 8)
    {
        std::cerr << "PhoneBook is full, replacing the oldest contact." << std::endl;
        current_contact = 0; 
    }

    Contact &contact = contacts[current_contact];
    std::string input;

    std::cout << "Enter your first name: ";
    std::getline(std::cin, input);
    contact.setFirstName(input);

    std::cout << "Enter your last name: ";
    std::getline(std::cin, input);
    contact.setLastName(input);

    std::cout << "Enter your nickname: ";
    std::getline(std::cin, input);
    contact.setNickname(input);

    std::cout << "Enter your phone number: ";
    std::getline(std::cin, input);
    contact.setPhoneNumber(input);

    std::cout << "Enter your darkest secret: ";
    std::getline(std::cin, input);
    contact.setDarkestSecret(input);

    current_contact++;
}

void PhoneBook::searchContact() const 
{
    std::cout << std::setw(10) << "Index" << '|';
    std::cout << std::setw(10) << "First name" << '|';
    std::cout << std::setw(10) << "Last name" << '|';
    std::cout << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < current_contact; ++i)
    {
        std::cout << std::setw(10) << i << '|';
        std::cout << std::setw(10) << contacts[i].getFirstName().substr(0, 9) << '|';
        std::cout << std::setw(10) << contacts[i].getLastName().substr(0, 9) << '|';
        std::cout << std::setw(10) << contacts[i].getNickname().substr(0, 9) << std::endl;
    }

    std::cout << "Enter the index of the contact to display: ";
    int index;
    std::cin >> index;
    if (std::cin.fail() || index < 0 || index >= current_contact)
    {
        std::cerr << "Invalid index." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    const Contact &contact = contacts[index];
    std::cout << "First name: " << contact.getFirstName() << std::endl;
    std::cout << "Last name: " << contact.getLastName() << std::endl;
    std::cout << "Nickname: " << contact.getNickname() << std::endl;
    std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
}


