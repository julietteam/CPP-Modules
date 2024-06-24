/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:05:23 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/24 15:05:06 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void convertFromInt(const std::string &literal)
{
    char *end;
    long val = std::strtol(literal.c_str(), &end, 10);
    int i = static_cast<int>(val);
    std::cout << "char: ";
    if (i >= std::numeric_limits<char>::min() && i <= std::numeric_limits<char>::max() \
    && isPrintable(static_cast<char>(i)))
        std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void convertFromFloat(const std::string &literal)
{
    char *end;
    float f = std::strtof(literal.c_str(), &end);
    std::cout << "char: ";
    if (f >= std::numeric_limits<char>::min() && f <= std::numeric_limits<char>::max() \
    && isPrintable(static_cast<char>(f)))
        std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int: ";
    if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
        std::cout << static_cast<int>(f) << std::endl;
    else
        std::cout << "impossible" << std::endl;
    std::cout << "float: " << f;
    if (f == static_cast<int>(f))
        std::cout << ".0f" << std::endl;
    else
        std::cout << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f);
    if (f == static_cast<int>(f))
        std::cout << ".0" << std::endl;
    else
        std::cout << std::endl;
}

void convertFromDouble(const std::string &literal)
{
    char *end;
    end = NULL;
    double d = std::strtod(literal.c_str(), &end);
    std::cout << "char: ";
    if (d >= std::numeric_limits<char>::min() && d <= std::numeric_limits<char>::max() \
    && isPrintable(static_cast<char>(d)))
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int: ";
    if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
        std::cout << static_cast<int>(d) << std::endl;
    else
        std::cout << "impossible" << std::endl;
    std::cout << "float: " << static_cast<float>(d);
    if (d == static_cast<int>(d))
        std::cout << ".0f" << std::endl;
    else
        std::cout << "f" << std::endl;
    std::cout << "double: " << d;
    if (d == static_cast<int>(d))
        std::cout << ".0" << std::endl;
    else
        std::cout << std::endl;
}
