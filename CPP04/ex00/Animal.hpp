/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:39:12 by julietteand       #+#    #+#             */
/*   Updated: 2024/03/12 22:31:47 by julietteand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(const std::string &type);
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);
	virtual ~Animal();

	virtual void makeSound() const;
	std::string getType() const;
};

#endif 