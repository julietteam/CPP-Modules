/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:40:36 by julietteand       #+#    #+#             */
/*   Updated: 2024/03/12 22:49:56 by julietteand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}
Animal::Animal(const std::string &type) : type(type)
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		type = other.type;
		std::cout << "Animal assignment operator called" << std::endl;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Some animal sound!" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}