/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:54:19 by julietteand       #+#    #+#             */
/*   Updated: 2024/03/12 23:16:10 by julietteand      ###   ########.fr       */
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

    // Test assignment operator with different objects
    Animal animal2 = cat; // Slicing, animal2 is an Animal, not a Cat.
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

    // Demonstrate polymorphism with assignment
    Animal *polyAnimal = new Dog();
    std::cout << "PolyAnimal is a " << polyAnimal->getType() << std::endl;
    polyAnimal->makeSound();

    *polyAnimal = animal; // This is object slicing! polyAnimal is still a Dog, but with Animal's data.
    std::cout << "PolyAnimal is now a " << polyAnimal->getType() << std::endl;
    polyAnimal->makeSound();

    delete polyAnimal; // Clean up dynamic memory

    return 0;
}
