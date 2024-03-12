/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:01:22 by julietteand       #+#    #+#             */
/*   Updated: 2024/03/12 22:01:24 by julietteand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>
#include <string>

class Dog : public Animal
{
public:
	Dog();
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
	virtual ~Dog();

	void makeSound() const;
};

#endif 