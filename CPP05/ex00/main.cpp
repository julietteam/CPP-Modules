/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:31:39 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/19 17:00:03 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "------------Instantiation------------------" << std::endl;
    Bureaucrat a("A", 151);
    Bureaucrat b("B", -2);
    Bureaucrat c("C", 42);

    std::cout << "------------Promotion----------------------" << std::endl;
    
    a.incrementGrade();
    std::cout << a << std::endl;
    b.incrementGrade();
    std::cout << b << std::endl;
    c.incrementGrade();
    std::cout << c << std::endl;
    
    std::cout << "-------------Retrograde--------------------" << std::endl;
    
    a.decrementGrade();
    std::cout << a << std::endl;
    b.decrementGrade();
    std::cout << b << std::endl;
    c.decrementGrade();
    std::cout << c << std::endl;
    
    return (0);
}