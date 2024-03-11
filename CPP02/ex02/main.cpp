/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:00:11 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/11 14:28:48 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    // Fixed a(10);
    // Fixed b(20);
    // const Fixed c = Fixed::max(a, b);
    // const Fixed d = Fixed::min(a, b);
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
    
    // std::cout << "La decrementation est egale a " << --a << std::endl;
    // std::cout << "La post-decrementation est egale a " << a-- << std::endl;
    // std::cout << "Le minimum est egal a " << Fixed::min(a, b) << std::endl;
    // std::cout << "Le const max est " << c << std::endl;
    // std::cout << "Le const min est " << d << std::endl;
    // std::cout << "L'addition est egale a " << a + b << std::endl;
    // std::cout << "La soustraction est egale a "<< a - b << std::endl;
    // std::cout << "La multiplication est egale a " << a * b << std::endl;
    // std::cout << "La division est egale a " << a / b << std::endl;
    // if (a < b)
    //     std::cout << "a est plus petit que b" << std::endl;
    // else
    //     std::cout << "a n'est pas plus petit que b" << std::endl;

    // if (a >= c)
    //     std::cout << "a est plus grand ou égal à c" << std::endl;
    // else
    //     std::cout << "a est plus petit que c" << std::endl;

    // if (a <= c)
    //     std::cout << "a est plus petit ou égal à c" << std::endl;
    // else
    //     std::cout << "a est plus grand que c" << std::endl;
    // if (a == c)
    //     std::cout << "a est égal à c" << std::endl;
    // else
    //     std::cout << "a n'est pas égal à c" << std::endl;
    // if (a != b)
    //     std::cout << "a est différent de b" << std::endl;
    // else
    //     std::cout << "a est égal à b" << std::endl;
    return (0);
}