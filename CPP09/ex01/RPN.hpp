/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:00:57 by juandrie          #+#    #+#             */
/*   Updated: 2024/07/01 16:24:09 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <exception>

class Rpn
{
private:
    std::stack<int> calcStack;

public:
    Rpn();
    Rpn(const Rpn &other);
    Rpn &operator=(const Rpn &other);
    ~Rpn();

    void push(double value);
    void performOperation(const std:: string &operation);
    double getResult() const;
    bool isOperator(const std::string &op) const;

    class ErrorException : public std::exception
	{
		public:
		const char *what(void) const throw();
	};
};


#endif 