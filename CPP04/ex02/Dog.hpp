/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:22:56 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/13 14:04:15 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Dog : public AAnimal
{
private:
	Brain *brain;

public:
	Dog();
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
	virtual ~Dog();

	void makeSound() const;
};

#endif 