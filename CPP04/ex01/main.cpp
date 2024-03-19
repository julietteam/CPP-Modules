/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:25:25 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/19 11:00:54 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <cstdlib> 
#include <ctime> 

// int main()
// {
//     const Animal *j = new Dog();
//     const Animal *i = new Cat();

    
//     delete j;
//     delete i;
    
//     return (0);
// }

int main()
{
    const int size = 10;
    Animal* animals[size];

    for (int i = 0; i < size / 2; ++i)
    {
        animals[i] = new Dog();
    }

    for (int i = size / 2; i < size; ++i)
    {
        animals[i] = new Cat();
    }

    for (int i = 0; i < size; ++i)
    {
        delete animals[i];
    }
    return (0);
}

// int main()
// {
//     Dog dog1;
//     Cat cat1;
//     dog1.makeSound(); // Doit afficher "Woof!"
//     cat1.makeSound(); // Doit afficher "Miaou"

//     std::cout << "Test des constructeurs de copie" << std::endl;
//     Dog dog2 = dog1;
//     Cat cat2 = cat1;
//     dog2.makeSound(); // Doit aussi afficher "Woof!"
//     cat2.makeSound(); // Doit aussi afficher "Miaou"

//     std::cout << "Test des opérateurs d'assignation" << std::endl;
//     Dog dog3;
//     dog3 = dog2;
//     Cat cat3;
//     cat3 = cat2;
//     dog3.makeSound(); // Doit afficher "Woof!"
//     cat3.makeSound(); // Doit afficher "Miaou"

//     std::cout << "Test du polymorphisme et des destructeurs" << std::endl;
//     Animal* animals[4];
//     animals[0] = new Dog();
//     animals[1] = new Cat();
//     animals[2] = new Dog(dog1);
//     animals[3] = new Cat(cat1);
//     for (int i = 0; i < 4; ++i)
//     {
//         animals[i]->makeSound();
//         delete animals[i];
//     }

//     return 0;
// }
