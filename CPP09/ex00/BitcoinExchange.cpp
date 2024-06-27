/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:30:26 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/27 19:36:37 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &date, float value) : date(date), value(value)
{
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
: rates(other.rates), date(other.date), value(other.value)
{
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        rates = other.rates;
        date = other.date;
        value = other.value;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}


bool BitcoinExchange::processInputFile(const char *filename, const std::map<std::string, float> &exchangeRates)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << "Error opening input file." << std::endl;
        return (false);
    }

    std::string line;
   // std::getline(file, line);
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string date, valueStr, separator;
        float value;

        if (!(iss >> date >> separator >> valueStr))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (!BitcoinExchange::dateIsValid(date))
        {
            std::cout << "Error: invalid date format => " << date << std::endl;
            continue;
        }
        std::istringstream valueStream(valueStr);
        if (!(valueStream >> value) || valueStream.fail() || !valueStream.eof())
        {
            std::cout << "Error processing input line: " << line << std::endl;
            continue;
        }
        if (value < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        float calculatedValue = BitcoinExchange::calculatedValue(exchangeRates, date, value);
        if (calculatedValue != -1)
        {
            std::cout << date << " => " << value << " = " << calculatedValue << std::endl;
        } 
        else
        {
            std::cout << "No exchange rate available for " << date << std::endl;
        }
    }

    file.close();
    return (true);
}

bool BitcoinExchange::loadDataFromFile(const char *filename, std::map<std::string, float> &data)
{
    std::ifstream file(filename);
    if (!file.is_open())
        return (false);

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::istringstream lineStream(line);
        std::string date;
        float rate;

        if (!std::getline(lineStream, date, ','))
        {
            continue;
        }

        if (!(lineStream >> rate))
        {
            continue;
        }
        data[date] = rate;
    }
    
    file.close();
    return (true);
}
float BitcoinExchange::findValueByDate(const std::map<std::string, float> &data, const std::string &date)
{
    std::map<std::string, float>::const_iterator it = data.find(date);
    if (it != data.end())
    {
        return (it->second);
    }

    it = data.lower_bound(date);
    if (it != data.begin())
    {
        --it;
        return (it->second);
    }
    return (-1);
}

float BitcoinExchange::calculatedValue(const std::map<std::string, float> &data, const std::string &date, float quantity)
{
    float rate = findValueByDate(data, date);
    
    if (rate == -1)
    {
        std::cout << "No data available for " << date << std::endl;
        return (-1);
    }

    float totalValue = quantity * rate;

    return (totalValue);
}

bool BitcoinExchange::dateIsValid(const std::string& date)
{
    if (date.length() != 10) 
        return (false);
    if (date[4] != '-' || date[7] != '-')
        return (false);
    
    int year, month, day;
    std::istringstream dateStream(date);
    dateStream >> year;
    if (dateStream.fail() || year < 2009 || year > 2022) 
        return (false);
    dateStream.ignore();
    dateStream >> month;
    if (dateStream.fail() || month < 1 || month > 12) 
        return (false);
    dateStream.ignore();
    dateStream >> day;
    if (dateStream.fail()) 
        return (false);
     if (day < 1 || day > 31)
        return false;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    if (month == 2)
    {
        if (day > 29)
            return false;
        if (day == 29 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)))
            return false;
    }
    if (year == 2009 && month == 1 && day < 2)
        return false;
    if (year == 2022 && month > 3)
        return false;
    if (year == 2022 && month == 3 && day > 29)
        return false;
    return (true);
}

