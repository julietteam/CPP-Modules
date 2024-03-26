/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutanStack.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:58:53 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/26 19:11:01 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANSTACK_HPP
#define MUTANSTACK_HPP

#include <iostream>
#include <string>
#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
public:

    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

   
    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack<T>& other) : std::stack<T>(other) {}
    MutantStack<T> &operator=(const MutantStack<T> &other)
    {
        std::stack<T>::operator=(other);
        return (*this);
    }
    ~MutantStack() {}


    iterator begin()
    {
        return (this->c.begin());
    }

    iterator end()
    {
        return (this->c.end());
    }

    const_iterator begin() const
    {
        return (this->c.begin());
    }

    const_iterator end() const 
    {
        return (this->c.end());
    }
};

#endif 