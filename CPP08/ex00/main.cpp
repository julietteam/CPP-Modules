/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:59:24 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/25 17:29:26 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void testVector()
{
    std::cout << "----------------" << std::endl;
    std::cout << "TEST AVEC VECTOR" << std::endl;
    std::cout << "----------------" << std::endl;
    
    std::vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(5);
    try
    {
        std::vector<int>::iterator result = easyfind(numbers, 3);
        std::cout << "Found value: " << *result << std::endl;
    }
    catch (const NotFoundException &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void testList()
{
    std::cout << "---------------" << std::endl;
    std::cout << "TEST AVEC LIST" << std::endl;
    std::cout << "---------------" << std::endl;
    
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    try
    {
        std::list<int>::iterator result = easyfind(lst, 0);
        std::cout << "Found value: " << *result << std::endl;
    }
    catch (const NotFoundException &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void testDeque()
{
    std::cout << "---------------" << std::endl;
    std::cout << "TEST AVEC DEQUE" << std::endl;
    std::cout << "---------------" << std::endl;
    
    std::deque<int> deq;
    deq.push_back(1);
    deq.push_back(2);
    deq.push_back(3);
    deq.push_back(4);
    deq.push_back(5);
    try
    {
        std::deque<int>::iterator result = easyfind(deq, 3);
        std::cout << "Found value: " << *result << std::endl;
    }
    catch (const NotFoundException &e)
    {
        std::cout << e.what() << std::endl;
    }
}

int main()
{
    testVector();
    testList();
    testDeque();
    
    return 0;
}