/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:12:48 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/07 13:22:33 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void Harl::debug(void)
{
    std::cout << "[DEBUG]: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.";
    std::cout << "I really do !" << std::endl;
}
void Harl::info(void)
{
    std::cout << "[INFO]: I cannot believe adding extra bacon costs more money.";
    std::cout << "You didn't put enough bacon in my burger !";
    std::cout << "If you did, I wouldn't be asking for more !" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[WARNING]: I think I deserve to have some extra bacon for free.";
    std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error(void)
{
    std::cout << "[ERROR]: This is unacceptable !";
    std::cout << "I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level)
{
    int levelNum = 0;
    
    if (level == "DEBUG")
        levelNum = 1;
    if (level == "INFO")
        levelNum = 2;
    if (level == "WARNING")
        levelNum = 3;
    if (level == "ERROR")
        levelNum = 4;

    switch (levelNum)
    {
        case 1:
            debug();
        case 2:
            info();
        case 3:
            warning();
        case 4:
            error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}