/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:20:31 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/06 13:14:16 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"


class PhoneBook
{
    private:
    Contact contacts[8];
    int     current_contact;
    
    public:
    PhoneBook();

    void addContact();
    void searchContact() const;
    std::string truncateString(const std::string& str) const;
    
    
};

#endif 