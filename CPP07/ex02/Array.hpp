/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:56:01 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/25 15:16:34 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <ctime>
#include <cstdlib>

template <typename T>
class Array
{
private:
    T *elements;
    unsigned int _size;
public:
    Array();
    Array(unsigned int n);
    Array(const Array &other);
    Array &operator=(const Array &other);
    ~Array();
    
    T &operator[](unsigned int index);
    const T &operator[](unsigned int index) const;
    
    unsigned int size() const;

    class IndexOutOfBoundsException : public std::exception
	{
		public :
		const char* what(void) const throw()
		{
			return ("[Exception] : index is out of bound !");
		}
	};
};



#include "Array.tpp"
#endif