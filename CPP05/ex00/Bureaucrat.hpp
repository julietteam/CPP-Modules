/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:22:00 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/06 16:05:49 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>


class Bureaucrat
{
private:
    const std::string name;
    int grade;
    
public:
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();
    
    const std::string &getName() const;
    int getGrade() const;
    
    void incrementGrade();
    void decrementGrade();

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
    
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif