/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:20:56 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/25 19:07:48 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template <typename T>
Array<T>::Array() : elements(new T[0]), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]), _size(n) {
    
}

template <typename T>
Array<T>::Array(const Array &other) : elements(new T[other._size]), _size(other._size)
{
    for (unsigned int i = 0; i < _size; i++)
    {
        elements[i] = other.elements[i];
    }
}
template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        delete []elements;
        _size = other._size;
        elements = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
        {
            elements[i] = other.elements[i];
        }
    }
    return (*this);
}

template <typename T>
Array<T>::~Array()
{
    delete []elements;
}
template <typename T>
T &Array<T>::operator[](unsigned int index)
{
        if (index >= _size)
        {
            throw std::exception();
        }
        return (elements[index]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
    {
        throw std::exception();
    }
    return (elements[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

