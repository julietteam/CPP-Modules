/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:20:49 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/25 14:22:12 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T const &min(T const &a, T const &b)
{
    if (a < b)
        return (a);
    return (b);
}

template <typename T>
T const &max(T const &a, T const &b)
{
    if (a > b)
        return (a);
    return (b);
}

#endif