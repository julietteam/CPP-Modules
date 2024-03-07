/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:07:41 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/07 13:24:55 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_FILTER_HPP
#define HARL_FILTER_HPP

#include <iostream>
#include <string>

class Harl
{
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

public:
    Harl();
    ~Harl();

    void    complain(std::string level);
};




#endif