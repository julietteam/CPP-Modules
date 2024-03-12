/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:41:43 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/12 13:27:01 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

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
