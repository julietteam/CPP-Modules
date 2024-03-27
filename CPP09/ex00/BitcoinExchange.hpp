/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:22:02 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/27 19:22:22 by juandrie         ###   ########.fr       */
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

class BitcoinExchange
{
private: 
    std::map<std::string, float> rates;
public:

    std::string date;
    float value;

    BitcoinExchange();
    BitcoinExchange(const std::string &date, float value);
    ~BitcoinExchange();


    static bool     loadDataFromFile(const char *filename, std::map<std::string, float> &data);
    static float    findValueByDate(const std::map<std::string, float>& data, const std::string& date);
    static bool     dateIsValid(const std::string& date);
    static float    calculatedValue(const std::map<std::string, float>& data, const std::string &date, float quantity);
    static bool     processInputFile(const char *filename, const std::map<std::string, float>& exchangeRates);
};

#endif