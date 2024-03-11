/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:37:35 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/11 11:53:41 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intVal) : rawBits(intVal << fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatVal) : rawBits(roundf(floatVal * (1 << fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
}
    
Fixed::Fixed(const Fixed &other) : rawBits(other.rawBits)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        rawBits = other.rawBits;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}


int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    
    return rawBits;
}

void Fixed::setRawBits(int const raw)
{
    rawBits = raw;
    std::cout << "setRawBits member function called" << std::endl;
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(rawBits) / (1 << fractionalBits)); 
}

int Fixed::toInt(void) const
{
    return (rawBits >> fractionalBits);
}

void Fixed::print(std::ostream &out) const
{
    out << toFloat();
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) 
{
    fixed.print(out);
    return out;
}