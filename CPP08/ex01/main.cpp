/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:25:42 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/26 14:13:20 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    
    std::cout << "-----------------------------" << std::endl;
    std::cout << "TEST STANDARD" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    
    Span sp = Span(5);
    
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

    std::cout << "-----------------------------" << std::endl;
    std::cout << "TEST AVEC VALEURS NÉGATIVES" << std::endl;
    std::cout << "-----------------------------" << std::endl;

    Span spNegatives = Span(5);

    spNegatives.addNumber(-5);
    spNegatives.addNumber(-4);
    spNegatives.addNumber(-3);
    spNegatives.addNumber(-2);
    spNegatives.addNumber(-1);
    

    std::cout << "Shortest Span: " << spNegatives.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << spNegatives.longestSpan() << std::endl;

    std::cout << "-------------------------------" << std::endl;
    std::cout << "TEST AVEC UN TABLEAU TROP PETIT" << std::endl;
    std::cout << "-------------------------------" << std::endl;

    Span sp3 = Span(2);

    try 
    {
        sp3.addNumber(5);
        sp3.addNumber(4);
        sp3.addNumber(3);
        sp3.addNumber(2);
        sp3.addNumber(1);
    }
    catch (const std::length_error &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << "Shortest Span: " << sp3.shortestSpan() << std::endl;
    }
    catch (const std::logic_error &e)
    {
        std::cerr << "Exception caught for shortestSpan: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Longest Span: " << sp3.longestSpan() << std::endl;
    }
    catch (const std::logic_error &e)
    {
        std::cerr << "Exception caught for longestSpan: " << e.what() << std::endl;
    }

    std::cout << "-------------------------------" << std::endl;
    std::cout << "TEST AVEC PAS ASSEZ DE VALEURS" << std::endl;
    std::cout << "-------------------------------" << std::endl;

    Span sp4 = Span(6);

    try
    {
        sp4.addNumber(5); 
        std::cout << "Shortest Span: " << sp4.shortestSpan() << std::endl;
    } 
    catch (const std::logic_error &e)
    {
        std::cerr << "Exception caught for shortestSpan: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Longest Span: " << sp4.longestSpan() << std::endl;
    }
    catch (const std::logic_error &e)
    {
        std::cerr << "Exception caught for longestSpan: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------" << std::endl;
    std::cout << "TEST AVEC ADDRANGE" << std::endl;
    std::cout << "-----------------------------" << std::endl;

    Span sp2 = Span(5);
    int array[] = {1, 2, 3, 4, 5};
    std::vector<int> numbers(array, array+ sizeof(array) / sizeof(array[0]));
    sp2.addRange(numbers.begin(), numbers.end());

    std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;
    
    std::cout << "-----------------------------" << std::endl;
    std::cout << "TEST DE addRange AVEC TAILLE EXCESSIVE" << std::endl;
    std::cout << "-----------------------------" << std::endl;

    Span sp5(3);
    int array2[] = {1, 2, 3, 4, 5};
    std::vector<int> numbers2(array2, array2 + sizeof(array2) / sizeof(array2[0]));
    try
    {
        sp5.addRange(numbers2.begin(), numbers2.end());
    }
    catch (const std::length_error &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------" << std::endl;
    std::cout << "TEST AVEC 10 000 et +" << std::endl;
    std::cout << "-----------------------------" << std::endl;

    const int N = 11000;
    Span largeSpan(N);
    
    std::vector<int> largeNumbers;
    for (int i = 0; i < N; ++i)
    {
        largeNumbers.push_back(i);
    }

    largeSpan.addRange(largeNumbers.begin(), largeNumbers.end());

    try 
    {
        std::cout << "Shortest Span: " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << largeSpan.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return (0);
}