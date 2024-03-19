/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:31:39 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/19 18:27:30 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    Bureaucrat juliette("Juliette", 2);
    Bureaucrat henri("Henri", 150);

    try
    {
        Form taxForm("Tax Form", 1, 1);
        juliette.signForm(taxForm);
        std::cout << taxForm << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception while processing taxForm: " << e.what() << std::endl;
    }

    try
    {
        Form permitForm("Permit Form", 3, 1);
        henri.signForm(permitForm);
        std::cout << permitForm << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception while processing permitForm: " << e.what() << std::endl;
    }

    try
    {
        Form illegalForm("Illegal Form", 0, 1); // Devrait lever une exception GradeTooHighException
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception while creating illegalForm: " << e.what() << std::endl;
    }

    try
    {
        Form anotherIllegalForm("Another Illegal Form", 151, 1); // Devrait lever une exception GradeTooLowException
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception while creating anotherIllegalForm: " << e.what() << std::endl;
    }

    try
    {
        juliette.incrementGrade();
        std::cout << juliette << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception while incrementing Juliette's grade: " << e.what() << std::endl;
    }

    try
    {
        henri.decrementGrade();
         std::cout << henri << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception while decrementing Henri's grade: " << e.what() << std::endl;
    }

    return 0;
}



// int main() {
//     try {
//         Bureaucrat juliette("Juliette", 2);
//         Bureaucrat henri("Henri", 150);
//         Form taxForm("Tax Form", 1, 1);
//         Form permitForm("Permit Form", 3, 1);
//        // Form illegalForm("Illegal Form", 0, 1); // Devrait lever une exception GradeTooHighException
//         //Form anotherIllegalForm("Another Illegal Form", 151, 1); // Devrait lever une exception GradeTooLowException

//         std::cout << juliette << std::endl;
//         std::cout << henri << std::endl;

//         // Juliette peut signer parce que son grade est suffisamment élevé.
//         juliette.signForm(taxForm);
//         std::cout << taxForm << std::endl;

//         // Henri ne peut pas signer parce que son grade est trop bas.
//         henri.signForm(permitForm);
//         std::cout << permitForm << std::endl;

//         // Tester l'incrémentation et la décrémentation des grades
//         juliette.incrementGrade();
//         std::cout << juliette << std::endl;
//         henri.decrementGrade(); // Devrait lever une exception GradeTooLowException

//     } catch (const GradeTooHighException& e) {
//         std::cerr << "Exception caught: " << e.what() << std::endl;
//     } catch (const GradeTooLowException& e) {
//         std::cerr << "Exception caught: " << e.what() << std::endl;
//     } catch (const std::exception& e) {
//         std::cerr << "Some other std::exception caught: " << e.what() << std::endl;
//     }

//     return 0;
// }
