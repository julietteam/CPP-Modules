/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:14:49 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/28 19:28:06 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

double PmergeMe::sortTime = 0;

int main(int argc, char** argv) {
    std::vector<int> numbers;

    for (int i = 1; i < argc; ++i)
    {
        // Utilisez atoi et gérez manuellement la conversion de type
        numbers.push_back(atoi(argv[i]));
    }

    PmergeMe sorter(numbers);

    // Utilisez clock() à la place de chrono pour C++98
    std::clock_t start = std::clock();
    sorter.sort();
    std::clock_t end = std::clock();
    
    // Calculez le temps écoulé avec ctime
    PmergeMe::setSortTime(static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000);

    std::cout << "Avant le tri: ";
    for (std::size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Après le tri: ";
    sorter.print();

    std::cout << "Temps pour trier: " << PmergeMe::getSortTime() << " millisecondes" << std::endl;

    return 0;
}