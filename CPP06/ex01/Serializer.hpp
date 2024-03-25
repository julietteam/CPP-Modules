/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:09:15 by julietteand       #+#    #+#             */
/*   Updated: 2024/03/25 11:26:15 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>

struct Data
{
    int number;
    std::string text;
};


class Serializer
{
public:
	Serializer();
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &other);
	~Serializer();

	static unsigned long serialize(Data *ptr);
	static Data *deserialize(unsigned long raw);
};


#endif 