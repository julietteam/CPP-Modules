/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:22:00 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/19 18:36:24 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Form.hpp"

class GradeTooHighException : public std::exception
{
    public:
    const char *what() const throw()
    {
        return ("Grade too high");
    }
};

class GradeTooLowException : public std::exception
{
    public:
    const char *what() const throw()
    {
        return ("Grade too low");
    }
};

class Bureaucrat
{
private:
    const std::string name;
    int grade;
public:
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();
    const std::string &getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(Form &form);
    
};

std::ostream &operator<<(std::ostream &os, Bureaucrat &b);

#endif