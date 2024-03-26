/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:49:11 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/26 14:42:38 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <exception>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = container.begin();
    while (it != container.end())
    {
        if (*it == value)
            return (it);
        it++;
    }
    return (container.end());
}

#endif