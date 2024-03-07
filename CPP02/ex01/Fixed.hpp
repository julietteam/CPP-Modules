/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:36:04 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/07 18:21:51 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{

private:
    int rawBits;
    static const int fractionalBits = 8;
    
public:
    Fixed();
    Fixed(const int intVal);
    Fixed(const float floatVal);
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();

    
    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;

    void print(std::ostream &out) const;
    
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif 