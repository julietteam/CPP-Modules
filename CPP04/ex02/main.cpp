/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:30:16 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/19 11:03:56 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const int numberOfAnimals = 4;
    AAnimal* animals[numberOfAnimals];

    for (int i = 0; i < numberOfAnimals; ++i)
    {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    for (int i = 0; i < numberOfAnimals; ++i)
    {
        animals[i]->makeSound();
    }

    for (int i = 0; i < numberOfAnimals; ++i)
    {
        delete animals[i];
    }
    // AAnimal animal;
    // AAnimal* animal = new AAnimal();

    return 0;
}
