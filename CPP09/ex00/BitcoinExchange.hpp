/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:22:02 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/28 18:33:18 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTC_HPP
#define BTC_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <limits>
#include <stdexcept>

class BitcoinExchange
{
private: 
    std::map<std::string, float> rates;

public:
    std::string date;
    float value;

    BitcoinExchange();
    BitcoinExchange(const std::string &date, float value);
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void            setDataBase();
    static int      convertToFloat(const std::string &valueStr, float &value);
    static bool      isValidFloat(const std::string &valueStr);
    static float    findValueByDate(const std::map<std::string, float>& data, const std::string& date);
    static int     dateIsValid(const std::string& date);
    static float    calculatedValue(const std::map<std::string, float>& data, const std::string &date, float quantity);
    static void     processInputFile(const char *filename, const std::map<std::string, float>& exchangeRates);
    class FileOpenException : public std::exception
    {
    public:
        virtual const char *what(void) const throw() 
        {
            return ("Error: could not open file.");
        }
    };

    class BadInputException : public std::exception
    {
        private:
            std::string message;
        public:
            BadInputException(const std::string &msg) : message("Error: bad input => " + msg) {}
            virtual const char *what(void) const throw() 
            {
                return (message.c_str());
            }
            virtual ~BadInputException() throw() {} 
    };

    class NBTooLargeException : public std::exception
    {
    public:
        virtual const char *what(void) const throw() 
        {
            return ("Error: too large a number.");
        }
    };
    class NegativeNumberException : public std::exception
    {
    public:
        virtual const char *what(void) const throw() 
        {
            return ("Error: not a positive number.");
        }
    };

};

#endif