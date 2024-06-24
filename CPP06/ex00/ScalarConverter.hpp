/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:52:29 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/24 15:28:43 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <limits>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();
    
public:
    static void convert(std::string literal);
    
};

bool    isPrintable(char c);
bool    isDigit(char c);
bool    isSpecialFloat(const std::string &literal);
void    handleSpecialTypes(const std::string &literal);
bool    isChar(const std::string &literal);
bool    isInt(const std::string &literal);
bool    isFloat(const std::string &literal);
bool    isDouble(const std::string &literal);
void    convertFromChar(const std::string &literal);

void    convertFromInt(const std::string &literal);
void    convertFromFloat(const std::string &literal);
void    convertFromDouble(const std::string &literal);

#endif 