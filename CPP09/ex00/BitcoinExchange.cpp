/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:30:26 by juandrie          #+#    #+#             */
/*   Updated: 2024/07/01 15:21:00 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

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
std::map<std::string, float> BitcoinExchange::getRates() const
{
    return rates;
}
bool BitcoinExchange::isValidFloat(const std::string &valueStr)
{
    bool isValidValue = true;
    bool hasDecimalPoint = false;
    std::string::size_type i = 0;
    if (valueStr[i] == '-')
    {
        i++;
        if (valueStr.length() == 1)
            return (false);
        throw (NegativeNumberException());
    }
    for (; i < valueStr.length(); ++i)
    {
        char c = valueStr[i];
        if (!isdigit(c))
        {
            if (c == '.' && !hasDecimalPoint)
            {
                hasDecimalPoint = true;
                if (i == 0 || i == valueStr.length() - 1)
                    return (false);
            }
            else
            {
                isValidValue = false;
                break;
            }
        }
    }
    return (true);
}

int BitcoinExchange::convertToFloat(const std::string &valueStr, float &value)
{
    std::istringstream valueStream(valueStr);
   
    if (!(valueStream >> value) || valueStream.fail() || !valueStream.eof())
        return (1);
    if (value < 0)
        throw (NegativeNumberException());
    if (value > 1000)
        throw (NBTooLargeException());
    return (0);
}
void BitcoinExchange::setDataBase()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
        throw FileOpenException();

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::istringstream lineStream(line);
        std::string date;
        float rate;

        if (!std::getline(lineStream, date, ','))
            continue;
        if (!(lineStream >> rate))
            continue;
        this->rates[date] = rate;
    }
    file.close();
}

void BitcoinExchange::checkSepErrors(std::string const &sep, std::string const &line)
{
        int spaces = 0;
        for (std::size_t i = 0; i < line.size(); ++i)
        {
            if (line[i] == ' ')
                spaces++;
        }
        if (spaces != 2 || sep != "|")
            throw BitcoinExchange::BadInputException(line);
}
void BitcoinExchange::processInputFile(const char *filename, const std::map<std::string, float> &exchangeRates)
{
    std::ifstream file(filename);
    if (!file.is_open())
        throw (FileOpenException());
    std::string line;
    bool isFirstLine = true;
    bool hasContent = false;
    while (std::getline(file, line))
    {
        if (isFirstLine)
        {
            isFirstLine = false;
            if (line == "date | value")
                continue;
        }
        hasContent = true;
        try
        {
            std::istringstream iss(line);
            std::string date, valueStr, separator;
            float floatValue;
            if (!(iss >> date >> separator >> valueStr))
                throw (BadInputException(line));
            checkSepErrors("|", line);
            BitcoinExchange::dateIsValid(date);
            if (!BitcoinExchange::isValidFloat(valueStr))
                throw BadInputException(line);
            std::istringstream valueStream(valueStr);
            if (BitcoinExchange::convertToFloat(valueStr, floatValue))
                throw BadInputException(line);
            float calculatedValue = BitcoinExchange::calculatedValue(exchangeRates, date, floatValue);
            if (calculatedValue != -1)
                std::cout << date << " => " << floatValue << " = " << calculatedValue << std::endl;
            else
                throw (BadInputException(line)); 
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    file.close();
    if (!hasContent)
        std::cerr << "Error: empty line in file." << std::endl;
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
        throw BadInputException(date);
    float totalValue = quantity * rate;
    return (totalValue);
}

void BitcoinExchange::dateIsValid(const std::string &date)
{
    if (date.empty() || date.length() != 10)
        throw (BadInputException(date)); 
    if (date[4] != '-' || date[7] != '-')
        throw (BadInputException(date));

    int year, month, day;
    std::istringstream dateStream(date);
    dateStream >> year;
    if (dateStream.fail() || year < 2009 || year > 2022)
        throw (BadInputException(date)); 
    dateStream.ignore();
    dateStream >> month;
    if (dateStream.fail() || month < 1 || month > 12)
        throw (BadInputException(date));
    dateStream.ignore();
    dateStream >> day;
    if (dateStream.fail())
        throw (BadInputException(date)); 
    if (day < 1 || day > 31)
        throw (BadInputException(date));
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
         throw (BadInputException(date)); 
    if (month == 2)
    {
        if (day > 29)
            throw (BadInputException(date));
        if (day == 29 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)))
            throw (BadInputException(date));   
    }
    if (year == 2009 && month == 1 && day < 2)
        throw (BadInputException(date));
    if (year == 2022 && month > 3)
        throw (BadInputException(date));
    if (year == 2022 && month == 3 && day > 29)
        throw (BadInputException(date));
}

