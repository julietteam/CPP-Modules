/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:20:14 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/19 18:42:42 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;


class Form
{
private:
    const std::string   name;
    bool        isSigned;
    const int   gradeRequiredToSign;
    const int   gradeRequiredToExecute;


public:
    Form(const std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();
    const std::string &getName() const;
    bool getIsSigned() const;
    int getGradeRequiredToSign() const;
    int getGradeRequiredToExecute() const;
    void beSigned(const Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif 