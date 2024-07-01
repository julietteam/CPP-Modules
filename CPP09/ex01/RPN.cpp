/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:01:42 by juandrie          #+#    #+#             */
/*   Updated: 2024/07/01 16:03:04 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

Rpn::Rpn() {}

Rpn::Rpn(const Rpn &other) : calcStack(other.calcStack)
{
}

Rpn &Rpn::operator=(const Rpn &other)
{
    if (this != &other)
    {
       calcStack = other.calcStack; 
    }
    return (*this);
}

Rpn::~Rpn()
{
}

void Rpn::push(double value)
{
    calcStack.push(value);
}

void Rpn::performOperation(const std:: string &operation)
{
    if (calcStack.size() < 2)
    {
        throw Rpn::ErrorException();
    }

    double b = calcStack.top();
    calcStack.pop();
    double a = calcStack.top();
    calcStack.pop();
    
    if (operation == "+")
        calcStack.push(a + b);
    else if (operation == "-")
        calcStack.push(a - b);
    else if (operation == "/")
    {
        if (b == 0)
            throw Rpn::ErrorException();
        calcStack.push(a / b);
    }
    else if (operation == "*")
        calcStack.push(a * b);
    else 
        throw Rpn::ErrorException();  

}

double Rpn::getResult() const 
{
    if (calcStack.size() != 1)
    {
        throw Rpn::ErrorException();
    }
    return (calcStack.top());
}

bool Rpn::isOperator(const std::string &op) const
{
    return (op == "+" || op == "-" || op == "*" || op == "/");
}

const char *Rpn::ErrorException::what() const throw()
{
    return ("Error");
}