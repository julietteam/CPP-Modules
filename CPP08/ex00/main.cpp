/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:59:24 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/26 14:48:23 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
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

    std::vector<int>::iterator result = easyfind(numbers, 3);
    if (result != numbers.end())
        std::cout << "Found value: " << *result << std::endl;
    else
        std::cout << "Value not found." << std::endl;


    std::cout << "---------------" << std::endl;
    std::cout << "TEST AVEC LIST" << std::endl;
    std::cout << "---------------" << std::endl;
    
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    std::list<int>::iterator res = easyfind(lst, 3);
    if (res != lst.end())
        std::cout << "Found value: " << *res << std::endl;
    else
        std::cout << "Value not found." << std::endl;
    
    std::cout << "---------------" << std::endl;
    std::cout << "TEST AVEC DEQUE" << std::endl;
    std::cout << "---------------" << std::endl;
    
    std::deque<int> deq;
    deq.push_back(1);
    deq.push_back(2);
    deq.push_back(3);
    deq.push_back(4);
    deq.push_back(5);
    std::deque<int>::iterator resu = easyfind(deq, 3);
    if (resu != deq.end())
        std::cout << "Found value: " << *resu << std::endl;
    else
        std::cout << "Value not found." << std::endl;
    return (0);
}