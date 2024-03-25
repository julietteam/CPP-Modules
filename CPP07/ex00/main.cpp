/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:17:32 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/25 16:58:52 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main()
{
    int a = 2;
    int b = 3;
    // char a = 'a';
    // char b = 'b';
    // double a = 1.5;
    // double b = 2.5;
    

    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

    int *ptr1 = &a;
    int *ptr2 = &b;
    std::cout << "ptr1 = " << ptr1 << ", ptr2 = " << ptr2 << std::endl;
    ::swap(ptr1, ptr2);
    std::cout << "*ptr1 = " << ptr1 << ", *ptr2 = " << ptr2 << std::endl;

    
    return (0);
}
