/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:04:20 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/28 19:24:27 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

class PmergeMe
{
private:
    std::vector<int> data;
    static double sortTime;

    void mergeSort(int leftIndex, int rightIndex);
    void merge(int leftIndex, int middleIndex, int rightIndex);

public:
    PmergeMe(std::vector<int> data);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void sort();
    void print() const;
    static double getSortTime();
    static void setSortTime(double time);
};



#endif 