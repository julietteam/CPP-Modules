/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:53:38 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/21 18:39:52 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

static bool isSpecialFloat(const std::string &literal)
{
    return literal == "nan" || literal == "nanf" ||
           literal == "-inf" || literal == "-inff" ||
           literal == "+inf" || literal == "+inff" ||
           literal == "inf";
}

static void handleSpecialTypes(const std::string &literal)
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


void ScalarConverter::convert(const std::string &literal)
{
    if (isSpecialFloat(literal))
    {
        handleSpecialTypes(literal);
        return;
    }

    if (literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
    {
        char c = literal[0];
        std::cout << "char: " << c << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return;
    }

    char *end;
    errno = 0;
    double d = strtod(literal.c_str(), &end);
    // Vérifier si la conversion a réussi sans dépasser le reste de la chaîne
    if (end != literal.c_str() && (*end == '\0' || *end == 'f' || *end == 'F'))
    {
        // Conversion réussie, essayer de convertir en int
        long i = static_cast<long>(d);

        // Conversion en char si possible
        if (i >= std::numeric_limits<char>::min() && \
        i <= std::numeric_limits<char>::max() && \
        std::isprint(static_cast<char>(i))) 
        {
            std::cout << "char: " << static_cast<char>(i) << std::endl;
        }
        else 
            std::cout << "char: Non displayable" << std::endl;

        // Conversion en int si dans les limites et pas de partie décimale
        if (d == i && i >= std::numeric_limits<int>::min() && i <= std::numeric_limits<int>::max())
        {
            std::cout << "int: " << i << std::endl;
        }
        else
            std::cout << "int: impossible" << std::endl;

        // Conversion en float et double est toujours possible ici
        std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
        std::cout << "double: " << d << ".0" << std::endl;
    }

}

