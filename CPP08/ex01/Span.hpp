/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:01:26 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/26 17:58:04 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <algorithm> 
#include <stdexcept> 
#include <limits> 

class Span
{
private:
    std::vector<int> numbers;
    unsigned int max_size;

public:
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int num);
    int shortestSpan();
    int longestSpan();
    template <typename Iterator>
    void addRange(Iterator begin, Iterator end)
    {
        for (Iterator it = begin; it != end; ++it)
        {
            addNumber(*it);
        }
    }
};




#endif 