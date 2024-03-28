/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:05:35 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/28 19:26:13 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::vector<int> data) : data(data)
{
}
PmergeMe::PmergeMe(const PmergeMe &other) : data(other.data)
{
}
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        data = other.data;
    }
    return (*this);
}
    
PmergeMe::~PmergeMe()
{
}
void mergeSort(int leftIndex, int rightIndex)
{
    if (leftIndex < rightIndex)
    {
        // Trouver le point milieu pour diviser le vecteur en deux moitiés
        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;

        // Trier la première et la deuxième moitié (appels récursifs)
        mergeSort(leftIndex, middleIndex);
        mergeSort(middleIndex + 1, rightIndex);

        // Fusionner les moitiés triées
        merge(leftIndex, middleIndex, rightIndex);
    }
}


void merge(int leftIndex, int middleIndex, int rightIndex)
{
   int n1 = middleIndex - leftIndex + 1; // Taille de la première moitié
    int n2 = rightIndex - middleIndex; // Taille de la deuxième moitié

    // Créer des vecteurs temporaires
    std::vector<int> leftHalf(n1), rightHalf(n2);

    // Copier les données dans les vecteurs temporaires
    std::copy_n(data.begin() + leftIndex, n1, leftHalf.begin());
    std::copy_n(data.begin() + middleIndex + 1, n2, rightHalf.begin());

    // Fusionner les vecteurs temporaires de retour dans le vecteur data_
    int i = 0; // Index initial de la première moitié
    int j = 0; // Index initial de la deuxième moitié
    int k = leftIndex; // Index initial du vecteur fusionné

    while (i < n1 && j < n2) {
        if (leftHalf[i] <= rightHalf[j]) {
            data[k] = leftHalf[i];
            i++;
        } else {
            data[k] = rightHalf[j];
            j++;
        }
        k++;
    }

    // Copier les éléments restants de leftHalf, s'il y en a
    while (i < n1) {
        data[k] = leftHalf[i];
        i++;
        k++;
    }

    // Copier les éléments restants de rightHalf, s'il y en a
    while (j < n2) {
        data[k] = rightHalf[j];
        j++;
        k++;
    } 
}
    
void PmergeMe::sort()
{
    if (data.empty())
        return;
    mergeSort(0, data.size() - 1);
}
void PmergeMe::print() const
{
    for (int num : data)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

double PmergeMe::getSortTime()
{
    return (sortTime);
}

void PmergeMe::setSortTime(double time)
{
    sortTime = time;
}