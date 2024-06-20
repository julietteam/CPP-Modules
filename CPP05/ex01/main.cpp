/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:31:39 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/20 10:17:17 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "------------Instantiation------------------" << std::endl;
    
    Bureaucrat A("A", 2);
    Bureaucrat B("B", 150);
    
    std::cout << "--------------- A TRY TO SIGN FORM------------" << std::endl;
    
    Form taxForm("Tax Form", 2, 2);
    A.signForm(taxForm);
    std::cout << taxForm << std::endl;

    std::cout << "--------------- B TRY TO SIGN FORM------------" << std::endl;
    
    Form taxForm2("Tax Form 2", 1, 150);
    B.signForm(taxForm2);
    std::cout << taxForm2 << std::endl;
    
    std::cout << "----------------TRY TO CREATE AND SIGN ILLEGALS FORMS----" << std::endl;
    
    Form illegalForm("Illegal Form", 0, 1);
    Form anotherIllegalForm("Another Illegal Form", 151, 1);
    
    std::cout << "----------------PROMOTION----------------------" << std::endl;
    
    A.incrementGrade();
    std::cout << A << std::endl;

    std::cout << "----------------RETROGRADE---------------------" << std::endl;
    B.decrementGrade();
    std::cout << B << std::endl;
    
    return (0);
}
