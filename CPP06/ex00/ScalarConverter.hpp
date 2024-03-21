/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:52:29 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/21 17:22:35 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <cerrno>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <cfloat>
#include <cmath>
#include <iomanip>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    
public:
    ~ScalarConverter();
    
    static void convert(const std::string &literal);
    
};


#endif 