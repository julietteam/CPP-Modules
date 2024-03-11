/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:01:45 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/11 13:28:22 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): rawBits(0)
{
}

Fixed::Fixed(const int intVal) : rawBits(intVal << fractionalBits)
{
}

Fixed::Fixed(const float floatVal) : rawBits(roundf(floatVal * (1 << fractionalBits)))
{
}
    
Fixed::Fixed(const Fixed &other) : rawBits(other.rawBits)
{
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        rawBits = other.rawBits;
    return *this;
}

Fixed::~Fixed()
{
}


int Fixed::getRawBits(void) const
{
    return rawBits;
}

void Fixed::setRawBits(int const raw)
{
    rawBits = raw;
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

bool Fixed::operator>(const Fixed &other) const
{ 
    return this->rawBits > other.rawBits; 
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->rawBits < other.rawBits;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->rawBits >= other.rawBits;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->rawBits <= other.rawBits;
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->rawBits == other.rawBits;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->rawBits != other.rawBits;
}

Fixed Fixed::operator+(const Fixed &other) const
{ 
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{ 
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{ 
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{ 
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++()
{
    this->rawBits++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++(*this);
    return temp;
}

Fixed &Fixed::operator--()
{
    this->rawBits--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --(*this);
    return temp;
}


Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a > b)
        return (b);
    else
        return (a);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return (b);
    else
        return (a);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

