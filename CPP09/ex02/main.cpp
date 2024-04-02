/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:14:49 by juandrie          #+#    #+#             */
/*   Updated: 2024/04/02 19:07:08 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int main(int argc, char** argv)
{
    std::vector<int> vector;
    std::deque<int> deque;

    for (int i = 1; i < argc; ++i)
    {
        int number = std::atoi(argv[i]);
        if (number <= 0)
        {
            std::cout << "Error" << std::endl;
            return (1);
        }
        vector.push_back(number);
        deque.push_back(number);
    }

    PmergeMe< std::vector<int> > sorterVector(vector);
    PmergeMe< std::deque<int> > sorterDeque(deque);

    std::cout << "Before: ";
    for (std::vector<int>::size_type i = 0; i < vector.size(); ++i)
    {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;

    clock_t startVector = clock();
    sorterVector.triVectorFordJohnson();
    clock_t endVector = clock();
    // sorterVector.print();

    clock_t startDeque = clock();
    sorterDeque.triDequeFordJohnson();
    clock_t endDeque = clock();
    // sorterDeque.print();
    
    PmergeMe< std::vector<int> >:: setVectorSortTime(static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000);
    PmergeMe< std::deque<int> >:: setDequeSortTime(static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000);

    std::cout << "After: ";
    sorterVector.print();

    std::cout << "Time to process a range of: " << vector.size() << " elements with std::vector: ";
    std::cout << PmergeMe< std::vector<int> >::getVectorSortTime() << " millisecondes" << std::endl;


    PmergeMe< std::deque<int> >::setDequeSortTime(static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000);

    std::cout << "Time to process a range of: " << deque.size() << " elements with std::deque: ";
    std::cout << PmergeMe< std::deque<int> >::getDequeSortTime() << " millisecondes" << std::endl;
    return 0;
}

// int main(int argc, char** argv) {
//     std::vector<int> vector;
//     std::deque<int> deque;

//     for (int i = 1; i < argc; ++i) {
//         int number = std::atoi(argv[i]);
//         if (number <= 0) {
//             std::cout << "Error" << std::endl;
//             return (1);
//         }
//         vector.push_back(number);
//         deque.push_back(number);
//     }

//     PmergeMe< std::vector<int> > sorterVector(vector);
//     PmergeMe< std::deque<int> > sorterDeque(deque);

//     std::cout << "Before: ";
//     for (std::vector<int>::size_type i = 0; i < vector.size(); ++i) {
//         std::cout << vector[i] << " ";
//     }
//     std::cout << std::endl;

//     // Tri et mesure du temps pour le vecteur
//     clock_t startVector = clock();
//     sorterVector.triVectorFordJohnson();
//     clock_t endVector = clock();
//     PmergeMe< std::vector<int> >::setVectorSortTime(static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000);

//     // Tri et mesure du temps pour le deque
//     // clock_t startDeque = clock();
//     // sorterDeque.triDequeFordJohnson();
//     // clock_t endDeque = clock();
//     // PmergeMe< std::deque<int> >::setDequeSortTime(static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000);

//     // Affichage des résultats triés
//     std::cout << "After (vector): ";
//     sorterVector.print();
//     // std::cout << "After (deque): ";
//     // sorterDeque.print();

//     // Affichage du temps de traitement
//     std::cout << "Time to process a range of: " << vector.size() << " elements with std::vector: " << PmergeMe< std::vector<int> >::getVectorSortTime() << " millisecondes" << std::endl;
//     std::cout << "Time to process a range of: " << deque.size() << " elements with std::deque: " << PmergeMe< std::deque<int> >::getDequeSortTime() << " millisecondes" << std::endl;

//     return 0;
// }
