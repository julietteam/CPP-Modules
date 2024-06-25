/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:17:32 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/25 14:33:10 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main()
{
    int a = 2;
    int b = 3;
    char e = 'a';
    char f = 'b';
    double g = 1.5;
    double h = 2.5;
    float i = 1.0f;
    float j = 0.0f;

    
    
    std::cout << "--------------TESTS AVEC DES INT---------" << std::endl;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

    std::cout << "--------------TESTS AVEC DES CHAR--------" << std::endl;
    ::swap(e, f);
    std::cout << "e = " << e << ", f = " << f << std::endl;
    std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
    std::cout << "max(e, f) = " << ::max(e, f) << std::endl;
    

    std::cout << "--------------TESTS AVEC DES DOUBLES--------" << std::endl;
    ::swap(g, h);
    std::cout << "g = " << g << ", h= " << h << std::endl;
    std::cout << "min(g, h) = " << ::min(g, h) << std::endl;
    std::cout << "max(g, h) = " << ::max(g, h) << std::endl;
    
    std::cout << "--------------TESTS AVEC DES FLOAT--------" << std::endl;
    ::swap(i, j);
    std::cout << "i = " << i << ", j= " << j << std::endl;
    std::cout << "min(i, j) = " << ::min(i, j) << std::endl;
    std::cout << "max(i, j) = " << ::max(i, j) << std::endl;
    
    std::cout << "--------------TESTS AVEC DES STRING---------" << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

    std::cout << "--------------TESTS AVEC DES ADRESSES---------" << std::endl;
    int *ptr1 = &a;
    int *ptr2 = &b;
    std::cout << "ptr1 = " << ptr1 << ", ptr2 = " << ptr2 << std::endl;
    ::swap(ptr1, ptr2);
    std::cout << "ptr1 = " << ptr1 << ", ptr2 = " << ptr2 << std::endl;

    
    return (0);
}
