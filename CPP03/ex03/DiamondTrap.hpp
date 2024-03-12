/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:25:49 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/12 13:38:55 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string _name;

public:
    DiamondTrap();
    DiamondTrap(const std::string &name);
    DiamondTrap(const DiamondTrap &other);
    DiamondTrap& operator=(const DiamondTrap &other);
    virtual ~DiamondTrap();

    void attack(const std::string &target);
    void whoAmI();


};

#endif // DIAMONDTRAP_HPP
