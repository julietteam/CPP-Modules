/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:41:43 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/12 19:36:31 by julietteand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class FragTrap : virtual public ClapTrap
{
    public:
    
    FragTrap();
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &other);
    FragTrap &operator=(const FragTrap &other);
    virtual ~FragTrap();

    void highFivesGuys(void);
};

#endif 
