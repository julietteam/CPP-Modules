/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:00:57 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/28 18:53:37 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>

class Rpn
{
private:
    std::stack<double> calcStack;

public:
    Rpn();
    Rpn(const Rpn &other);
    Rpn &operator=(const Rpn &other);
    ~Rpn();

    void push(double value);
    void performOperation(const std:: string &operation);
    double getResult() const;
    bool isOperator(const std::string &op) const;
};


#endif 