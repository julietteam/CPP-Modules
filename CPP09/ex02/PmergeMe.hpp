/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:04:20 by juandrie          #+#    #+#             */
/*   Updated: 2024/04/03 18:59:37 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <climits>
#include <stdexcept>
#include <string>
#include <cerrno>


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

    static void check_arguments(int argc, char **argv, std::vector<int> &vector, std::deque<int> &deque);
    
    void triVectorFordJohnson();
    void triDequeFordJohnson();

    void insertionSort(std::vector<int> &vec, int left, int right);
    int selectPivot(std::vector<int> &vec, int left, int right);
    int findMedian(std::vector<int> &vec, int left, int right);
    int partition(std::vector<int> &vec, int left, int right, int pivot);
    void mergeInsertSort(std::vector<int> &vec, int left, int right);

    void insertionSortDeque(std::deque<int> &deq, int left, int right);
    int findMedianDeque(std::deque<int> &deq, int left, int right);
    int selectPivotDeque(std::deque<int> &deq, int left, int right);
    int partitionDeque(std::deque<int> &deq, int left, int right, int pivot);
    void mergeInsertSortDeque(std::deque<int> &deq, int left, int right);
    
    class InvalidArgumentException : public std::runtime_error
    {
    public:
        InvalidArgumentException(const std::string &msg) : std::runtime_error(msg) {}
    };

    class OverflowException : public std::runtime_error
    {
    public:
        OverflowException(const std::string &msg) : std::runtime_error(msg) {}
    };
    
};

template <typename T>
double PmergeMe<T>::vectorSortTime = 0;
template <typename T>
double PmergeMe<T>::dequeSortTime = 0;

#endif 