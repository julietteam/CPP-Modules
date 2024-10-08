/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:20:28 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/06 12:55:06 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <limits>
#include <iomanip> 
#include <cstdlib>

PhoneBook::PhoneBook() : current_contact(0) {
}

void askForInput(const std::string &field_name, std::string &input)
{
    while (true)
    {
        std::cout << "Enter " << field_name << ": ";
        std::getline(std::cin, input);
        if (std::cin.eof())
        {
            std::cout << "\nEOF detected. Exiting the program." << std::endl;
            std::exit(EXIT_FAILURE);
        }
        if (!input.empty())
        {
            if (field_name == "phone number")
            {
                bool is_digit = true;
                for (std::size_t i = 0; i < input.length() ; ++i)
                {
                    char c = input[i];
                    if (!std::isdigit(c))
                    {
                        is_digit = false;
                        break;
                    }
                }
                if (!is_digit)
                {
                    std::cerr << "Invalid phone number. Please enter only digits." << std::endl;
                    continue;
                }
            }
            break;
        }
        else
        {
            std::cerr << field_name << " cannot be empty. Please enter a valid " << field_name << "." << std::endl;
        }
    }
}


void PhoneBook::addContact()
{
    int index = current_contact % 8;
    Contact &contact = contacts[index];
    std::string input;
    
    if (current_contact >= 8)
    {
        std::cerr << "PhoneBook is full, replacing the oldest contact." << std::endl;
        current_contact = 7;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    askForInput("first name", input);
    contact.setFirstName(input);

    askForInput("last name", input);
    contact.setLastName(input);

    askForInput("nickname", input);
    contact.setNickname(input);

    askForInput("phone number", input);
    contact.setPhoneNumber(input);

    askForInput("darkest secret", input);
    contact.setDarkestSecret(input);
    
    current_contact++;
}

std::string PhoneBook::truncateString(const std::string &str) const
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    else
        return str;
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
        std::cout << std::setw(10) << truncateString(contacts[i].getFirstName()) << '|';
        std::cout << std::setw(10) << truncateString(contacts[i].getLastName()) << '|';
        std::cout << std::setw(10) << truncateString(contacts[i].getNickname()) << std::endl;
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


