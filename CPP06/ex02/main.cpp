/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:13:05 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/24 15:55:28 by juandrie         ###   ########.fr       */
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

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "[pointer] : the object is of type A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "[pointer] : the object is of type B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "[pointer] : the object is of type C" << std::endl;
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "[reference] : the object is of type A" << std::endl;
        return;
    }
    catch (const std::exception &e)
    {
        std::cout << "[reference] : the object isn't of type A" << std::endl;
    }
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "[reference] : the object is of type B" << std::endl;
        return;
    }
    catch (const std::exception &e)
    {
        std::cout << "[reference] : the object isn't of type B" << std::endl;
    }
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "[reference] : the object is of type C" << std::endl;
        return;
    }
    catch (const std::exception &e)
    {
        std::cout << "[reference] : the object isn't of type C" << std::endl;
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