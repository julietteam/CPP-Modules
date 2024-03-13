/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:54:19 by julietteand       #+#    #+#             */
/*   Updated: 2024/03/13 11:07:55 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/*
int main()
{
	//const Animal *meta = new Animal(); 
	//const Animal *j = new Dog();
	//const Animal *i = new Cat();
	
	const WrongAnimal *meta = new WrongAnimal();
	const WrongAnimal *j = new WrongCat();
	
	std::cout << j->getType() << " " << std::endl; 
	//std::cout << i->getType() << " " << std::endl; 
	//i->makeSound();
	j->makeSound();
    meta->makeSound();

	//delete i;
	delete j;
	delete meta;
	
	return 0; 
}
*/

int main()
{
    Dog dog;
    Cat cat;
    Animal animal;

    std::cout << dog.getType() << " says ";
    dog.makeSound();

    std::cout << cat.getType() << " says ";
    cat.makeSound();

    std::cout << animal.getType() << " says ";
    animal.makeSound();

    Animal animal2 = cat;
    std::cout << "Animal2 is a " << animal2.getType() << std::endl;
    animal2.makeSound();

    Dog dog2;
    dog2 = dog;
    std::cout << "Dog2 is a " << dog2.getType() << std::endl;
    dog2.makeSound();

    Cat cat2;
    cat2 = cat;
    std::cout << "Cat2 is a " << cat2.getType() << std::endl;
    cat2.makeSound();

   
    Animal *polyAnimal = new Dog();
    std::cout << "PolyAnimal is a " << polyAnimal->getType() << std::endl;
    polyAnimal->makeSound();

    *polyAnimal = animal;
    std::cout << "PolyAnimal is now a " << polyAnimal->getType() << std::endl;
    polyAnimal->makeSound();

    delete polyAnimal;

    return 0;
}
