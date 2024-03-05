/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:17:08 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/05 18:33:02 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string *stringPTR = &brain;
    std::string &stringREF(brain);

    std::cout << "Address of brain: " << &brain << std::endl;
    std::cout << "Address stored in stringPTR: " << &stringPTR << std::endl;
    std::cout << "Address stored in stringREF: " << &stringREF << std::endl;

    std::cout << "Value of brain: " << brain << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

    return (0);
}