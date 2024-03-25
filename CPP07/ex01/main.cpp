/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:08:04 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/25 17:52:17 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void printInt(const int &element)
{
    std::cout << element << std::endl;
}
void printString(const std::string &element)
{
    std::cout << element << std::endl;
}
void printDouble(const double &element)
{
    std::cout << element << std::endl;
}

void printFloat(const float &element)
{
    std::cout << element << "f" << std::endl;
}

int main()
{
    std::cout << "------------" << std::endl;
    std::cout << "TEST DES INT" << std::endl;
    std::cout << "------------" << std::endl;
    int arrayInt[] = {1, 2, 3, 4, 5};
    size_t intLength = sizeof(arrayInt) / sizeof(int);
    iter(arrayInt, intLength, printInt);

    std::cout << "---------------" << std::endl;
    std::cout << "TEST DES DOUBLE" << std::endl;
    std::cout << "---------------" << std::endl;
    double arrayDouble[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleLength = sizeof(arrayDouble) / sizeof(double);
    iter(arrayDouble, doubleLength, printDouble);

    std::cout << "---------------" << std::endl;
    std::cout << "TEST DES FLOAT" << std::endl;
    std::cout << "---------------" << std::endl;
    float arrayFloat[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    size_t floatLength = sizeof(arrayFloat) / sizeof(float);
    iter(arrayFloat, floatLength, printFloat);

    std::cout << "---------------" << std::endl;
    std::cout << "TEST DES STRING" << std::endl;
    std::cout << "---------------" << std::endl;
    std::string arrayString[] = {"one", "two", "three", "four", "five"};
    size_t stringLength = sizeof(arrayString) / sizeof(std::string);
    iter(arrayString, stringLength, printString);

    return 0;
}