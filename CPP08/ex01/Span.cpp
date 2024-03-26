/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:07:33 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/26 16:50:37 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : max_size(N)
{
    std::cout << "Span constructor called" << std::endl;
}
Span::Span(const Span &other) : numbers(other.numbers), max_size(other.max_size)
{
    std::cout << "Span copy constructor called" << std::endl;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
       std::cout << "Span assignment operator called" << std::endl;
       numbers = other.numbers;
       max_size = other.max_size;
    }
    return (*this);
    
}

Span::~Span()
{
   std::cout << "Span destructor called" << std::endl; 
}

void Span::addNumber(int num)
{
    if (numbers.size() >= max_size)
        throw std::length_error("Span is already full.");
    numbers.push_back(num);
}

int Span::shortestSpan()
{
    if (numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find a span.");
    std::sort(numbers.begin(), numbers.end());
    int shortest = std::numeric_limits<int>::max();
    for (size_t i = 0; i < numbers.size() - 1; ++i)
    {
        int diff = numbers[i + 1] - numbers[i];
        if (diff < shortest) 
            shortest = diff;
    }
    return (shortest);
}

int Span::longestSpan()
{
    if (numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find a span.");

    int min = *std::min_element(numbers.begin(), numbers.end());
    int max = *std::max_element(numbers.begin(), numbers.end());
    
    return (max - min);
}


