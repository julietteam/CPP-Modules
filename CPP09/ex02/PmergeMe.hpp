/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:04:20 by juandrie          #+#    #+#             */
/*   Updated: 2024/04/02 19:04:38 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <typeinfo>

template <typename T>
class PmergeMe
{
private:
    T data;
    static double vectorSortTime;
    static double dequeSortTime;
    
public:
    PmergeMe(const T &data);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void print() const;
    static double getVectorSortTime();
    static void setVectorSortTime(double time);
    static double getDequeSortTime();
    static void setDequeSortTime(double time);

    void triVectorFordJohnson();
    void triDequeFordJohnson();

    void insertionSort(std::vector<int> &vec, int left, int right);
    int findMedian(std::vector<int>& vec, int left, int right);
    int partition(std::vector<int>& vec, int left, int right, int pivot);
    void mergeInsertSort(std::vector<int>& vec, int left, int right);

    void insertionSortDeque(std::deque<int>& deq, int left, int right);
    int findMedianDeque(std::deque<int>& deq, int left, int right);
    int partitionDeque(std::deque<int>& deq, int left, int right, int pivot);
    void mergeInsertSortDeque(std::deque<int> &deq, int left, int right);
    
};

template <typename T>
double PmergeMe<T>::vectorSortTime = 0;
template <typename T>
double PmergeMe<T>::dequeSortTime = 0;

#endif 