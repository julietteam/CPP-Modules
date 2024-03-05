/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:47:58 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/05 15:56:53 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"


Contact::Contact() {
    first_name = "";
    last_name = "";
    nickname = "";
    phone_number = "";
    darkest_secret = "";
}

Contact::~Contact() {
}

void Contact::setFirstName(const std::string &fn)
{
    first_name = fn;
}

std::string Contact::getFirstName() const
{
    return first_name;
}

void Contact::setLastName(const std::string &ln)
{
    last_name = ln;
}

std::string Contact::getLastName() const
{
    return last_name;
}

void Contact::setNickname(const std::string &n)
{
    nickname = n;
}

std::string Contact::getNickname() const
{
    return nickname;
}

void Contact::setPhoneNumber(const std::string &pn)
{
    phone_number = pn;
}

std::string Contact::getPhoneNumber() const
{
    return phone_number;
}

void Contact::setDarkestSecret(const std::string &ds)
{
    darkest_secret = ds;
}

std::string Contact::getDarkestSecret() const
{
    return darkest_secret;
}