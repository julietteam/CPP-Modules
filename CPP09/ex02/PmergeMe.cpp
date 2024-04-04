/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:05:35 by juandrie          #+#    #+#             */
/*   Updated: 2024/04/04 11:30:26 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


template <typename T>
PmergeMe<T>::PmergeMe(const T &data) : data(data)
{
}
template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe &other) : data(other.data)
{
}

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        data = other.data;
    }
    return (*this);
}

template <typename T>  
PmergeMe<T>::~PmergeMe()
{
}
template <typename T>  
void PmergeMe<T>::check_arguments(int argc, char **argv, std::vector<int> &vector, std::deque<int> &deque)
{
    if (argc <= 1)
        throw InvalidArgumentException("Invalid arguments.");
    
    for (int i = 1; i < argc; ++i)
    {
        char *end;
        errno = 0;
        long number = std::strtol(argv[i], &end, 10);
        if (*end != '\0')
            throw InvalidArgumentException("Invalid arguments.");
        if (errno == ERANGE || number <= 0 || number > INT_MAX)
           throw OverflowException("Error");
        vector.push_back(static_cast<int>(number));
        deque.push_back(static_cast<int>(number));
    }
}
template class PmergeMe<int>;

template<typename T>
void PmergeMe<T>::insertionSort(std::vector<int> &vec, int left, int right)
{
    for (int i = left + 1; i <= right; ++i)
    {
        int key = vec[i];
        int j = i - 1;

        while (j >= left && vec[j] > key)
        {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}
template<typename T>
int PmergeMe<T>::findMedian(std::vector<int> &vec, int left, int right)
{
    insertionSort(vec, left, right);
    return (vec[left + (right - left) / 2]);
}
template<typename T>
int PmergeMe<T>::selectPivot(std::vector<int> &vec, int left, int right)
{
    if (right - left < 5)
        return (findMedian(vec, left, right));

    std::vector<int> medians;
    for (int i = left; i <= right; i += 5)
    {
        int subRight = i + 4;
        if (subRight > right)
            subRight = right;

        int median = findMedian(vec, i, subRight);
        medians.push_back(median);
    }

    return (selectPivot(medians, 0, medians.size() - 1));
}

template<typename T>
int PmergeMe<T>::partition(std::vector<int> &vec, int left, int right, int pivot)
{
    while (left <= right)
    {
        while (vec[left] < pivot)
            left++;
        while (vec[right] > pivot)
            right--;
        if (left <= right)
        {
            std::swap(vec[left], vec[right]);
            left++;
            right--;
        }
    }
    return (left);
}

template<typename T>
void PmergeMe<T>::mergeInsertSort(std::vector<int> &vec, int left, int right)
{
    if (left >= right)
        return; 
    for (int i = left; i < right; i += 2)
    {
        if (i + 1 <= right)
        {
            if (vec[i] > vec[i + 1])
                std::swap(vec[i], vec[i + 1]);
        }
    }
    if (right - left + 1 <= 5)
    {
        insertionSort(vec, left, right);
        return;
    }
    int pivot = selectPivot(vec, left, right);

    int partitionIndex = partition(vec, left, right, pivot);
    mergeInsertSort(vec, left, partitionIndex - 1);
    mergeInsertSort(vec, partitionIndex, right);
}

template<>
void PmergeMe< std::vector<int> >::triVectorFordJohnson()
{
    mergeInsertSort(data, 0, data.size() - 1);
}


template<typename T>
void PmergeMe<T>::insertionSortDeque(std::deque<int> &deq, int left, int right) 
{
    for (int i = left + 1; i <= right; ++i)
    {
        int key = deq.at(i);
        int j = i - 1;

        while (j >= left && deq.at(j) > key)
        {
            deq.at(j + 1) = deq.at(j);
            j--;
        }
        deq.at(j + 1) = key;
    }
}

template<typename T>
int PmergeMe<T>::findMedianDeque(std::deque<int> &deq, int left, int right)
{
    insertionSortDeque(deq, left, right);
    return deq.at(left + (right - left) / 2);
}
template<typename T>
int PmergeMe<T>::selectPivotDeque(std::deque<int> &deq, int left, int right)
{
    if (right - left < 5)
        return (findMedianDeque(deq, left, right));

    std::vector<int> medians;
    for (int i = left; i <= right; i += 5)
    {
        int subRight = i + 4;
        if (subRight > right)
            subRight = right;

        int median = findMedianDeque(deq, i, subRight);
        medians.push_back(median);
    }

    return (selectPivot(medians, 0, medians.size() - 1));
}
template<typename T>
int PmergeMe<T>::partitionDeque(std::deque<int> &deq, int left, int right, int pivot)
{
    while (left <= right)
    {
        while (deq.at(left) < pivot)
            left++;
        while (deq.at(right) > pivot)
            right--;
        if (left <= right)
        {
            std::swap(deq.at(left), deq.at(right));
            left++;
            right--;
        }
    }
    return (left);
}

template<typename T>
void PmergeMe<T>::mergeInsertSortDeque(std::deque<int> &deq, int left, int right)
{
    if (left >= right)
        return;
    for (int i = left; i < right; i += 2)
    {
        if (i + 1 <= right)
        {
            if (deq[i] > deq[i + 1])
                std::swap(deq[i], deq[i + 1]);
        }
    }
    if (right - left + 1 <= 5)
    {
        insertionSortDeque(deq, left, right);
        return;
    }

    int pivot = selectPivotDeque(deq, left, right);

    int partitionIndex = partitionDeque(deq, left, right, pivot);
    mergeInsertSortDeque(deq, left, partitionIndex - 1);
    mergeInsertSortDeque(deq, partitionIndex, right);
}

template<>
void PmergeMe< std::deque<int> >::triDequeFordJohnson()
{
        mergeInsertSortDeque(data, 0, data.size() - 1);
}

template <typename T> 
void PmergeMe<T>::print() const
{
    for (typename T::const_iterator it = data.begin(); it != data.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename T> 
double PmergeMe<T>::getVectorSortTime()
{
    return (vectorSortTime);
}
template <typename T> 
void PmergeMe<T>::setVectorSortTime(double time)
{
    vectorSortTime = time;
}

template <typename T> 
double PmergeMe<T>::getDequeSortTime()
{
    return (dequeSortTime);
}
template <typename T> 
void PmergeMe<T>::setDequeSortTime(double time)
{
    dequeSortTime = time;
}

template class PmergeMe< std::vector<int> >;
template class PmergeMe< std::deque<int> >;