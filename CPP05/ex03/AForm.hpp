/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:20:14 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/19 19:55:44 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;


class AForm
{
private:
    const std::string   name;
    bool        isSigned;
    const int   gradeRequiredToSign;
    const int   gradeRequiredToExecute;


public:
    AForm();
    AForm(const std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm() = 0;
    
    const std::string &getName() const;
    bool getIsSigned() const;
    int getGradeRequiredToSign() const;
    int getGradeRequiredToExecute() const;
    
    void beSigned(const Bureaucrat &b);

    virtual void execute(const Bureaucrat &executor) const = 0;

    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return ("Grade too high\n");
        }
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return ("Grade too low\n");
        }
    };
    class AlreadySignedException : public std::exception
	{
		public:
		const char* what(void) const throw()
        {
            return ("Form already signed\n");
        }
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &aForm);

#endif 