/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:13:05 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/25 16:13:44 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base *generate(void)
{
    srand(time(NULL));

    switch(rand() % 3)
    {
        case 0:
            return (new A());
        case 1:
            return (new B());
        case 2:
            return (new C());
    }
    return (NULL);
    
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A pointer was identified" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B pointer was identified" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C pointer was identified" << std::endl;
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A reference was identified" << std::endl;
        return;
    }
    catch (const std::exception &e)
    {
        std::cout << "Is not a A reference" << std::endl;
    }
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B reference was identified" << std::endl;
        return;
    }
    catch (const std::exception &e)
    {
        std::cout << "Is not a B reference" << std::endl;
    }
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C reference was identified" << std::endl;
        return;
    }
    catch (const std::exception &e)
    {
        std::cout << "Is not a C reference" << std::endl;
    }
}
int main()
{
    Base *p = generate();
    
    identify(p);
    std::cout << "Pointer: " << p << std::endl;
    identify(*p);
    std::cout << "Reference: " << p << std::endl;
    
    delete (p);

    return (0);
}