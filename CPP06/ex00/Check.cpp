/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Check.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:07:14 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/24 15:01:41 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool isPrintable(char c)
{
    return c >= 32 && c <= 126;
}

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

bool isSpecialFloat(const std::string &literal)
{
    return literal == "nan" || literal == "nanf" ||
           literal == "-inf" || literal == "-inff" ||
           literal == "+inf" || literal == "+inff" ||
           literal == "inf";
}

void handleSpecialTypes(const std::string &literal)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (literal == "nan" || literal == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (literal == "-inf" || literal == "-inff") 
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    } 
    else if (literal == "+inf" || literal == "+inff" || literal == "inf") 
    {
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
    }
}
bool isChar(const std::string &literal)
{
    return (literal.size() == 1 && isPrintable(literal[0]) \
    && !isDigit(literal[0]));
}

bool isInt(const std::string &literal)
{
    char *end;
    end = NULL;
    long val = std::strtol(literal.c_str(), &end, 10);
    return (*end == '\0' && val >= std::numeric_limits<int>::min() \
    && val <= std::numeric_limits<int>::max());
}

bool isFloat(const std::string &literal)
{
    char *end;
    end = NULL;
    std::strtof(literal.c_str(), &end);
    return (*end == 'f' || *end == '\0') && end != literal.c_str();
}

bool isDouble(const std::string &literal)
{
    char *end;
    end = NULL;
    std::strtod(literal.c_str(), &end);
    return (*end == '\0' && end != literal.c_str());
}

void convertFromChar(const std::string &literal)
{
    char c = literal[0];
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}
