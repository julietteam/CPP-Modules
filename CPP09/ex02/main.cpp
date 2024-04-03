/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:14:49 by juandrie          #+#    #+#             */
/*   Updated: 2024/04/03 18:36:06 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int main(int argc, char** argv)
{
    std::vector<int> vector;
    std::deque<int> deque;

    try 
    {
        PmergeMe<int>::check_arguments(argc, argv, vector, deque);
    

        PmergeMe< std::vector<int> > sorterVector(vector);
        PmergeMe< std::deque<int> > sorterDeque(deque);

        std::cout << "Before: ";
        sorterVector.print();

        clock_t startVector = clock();
        sorterVector.triVectorFordJohnson();
        clock_t endVector = clock();
        

        clock_t startDeque = clock();
        sorterDeque.triDequeFordJohnson();
        clock_t endDeque = clock();
        
        double timeVector = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000000;
        PmergeMe< std::vector<int> >:: setVectorSortTime(timeVector);

        double timeDeque = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000;
        PmergeMe< std::deque<int> >:: setDequeSortTime(timeDeque);

        std::cout << "After: ";
        sorterVector.print();

        std::cout << "Time to process a range of: " << vector.size() << " elements with std::vector: ";
        std::cout << PmergeMe< std::vector<int> >::getVectorSortTime() << " microsecondes" << std::endl;


        std::cout << "Time to process a range of: " << deque.size() << " elements with std::deque: ";
        std::cout << PmergeMe< std::deque<int> >::getDequeSortTime() << " microsecondes" << std::endl;
    }
    catch (const PmergeMe<int>::InvalidArgumentException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const PmergeMe<int>::OverflowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}

