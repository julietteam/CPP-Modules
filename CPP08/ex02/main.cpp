/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:00:20 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/26 17:35:31 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutanStack.hpp"
#include <list>
#include <vector>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "\033[31m" << "------TEST MUTAN STACK-------" << "\033[0m" << std::endl;
    std::cout << "DERNIER ELEMENT AJOUTE: " << std::endl;
    std::cout << mstack.top() << std::endl;
    
    std::cout << "TAILLE DE LA STACK: " << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    
    std::cout << "CONTENU DE LA STACK:" << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "TEST COPIE DE LA STACK" << std::endl;
    std::stack<int> copy(mstack);
    std::cout << "TAILLE DE LA STACK COPIEE: " << copy.size() << std::endl;
    std::cout << "CONTENU DE LA STACK COPIEE:" << std::endl;
    while (!copy.empty())
    {
        std::cout << copy.top() << std::endl;
        copy.pop();
    }
    

    std::cout << "\033[31m" << "----------------------" << "\033[0m" << std::endl;

    std::cout << "\033[35m" << "------TEST LIST-------" << "\033[0m" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    
    std::cout << "DERNIER ELEMENT AJOUTE: " << std::endl;
    std::cout << lst.back() << std::endl;
    
    std::cout << "TAILLE DE LA LISTE: " << std::endl;
    lst.pop_back();
    std::cout << lst.size() << std::endl;
    

    std::cout << "CONTENU DE LA LISTE:" << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    std::list<int>::iterator it1 = lst.begin();
    std::list<int>::iterator ite1 = lst.end();
    
    while (it1 != ite1)
    {
        std::cout << *it1 << std::endl;
        ++it1;
    }
    
    std::cout << "\033[35m" << "------------------------" << "\033[0m" << std::endl;
    
    std::cout << "\033[36m" << "------TEST VECTOR-------" << "\033[0m" << std::endl;
    std::vector<int> v;
    v.push_back(5);
    v.push_back(17);
    
    std::cout << "DERNIER ELEMENT AJOUTE: " << std::endl;
    std::cout << v.back() << std::endl;
    
    std::cout << "TAILLE DU VECTOR: " << std::endl;
    v.pop_back();
    std::cout << v.size() << std::endl;
    
    std::cout << "CONTENU DU VECTOR:" << std::endl;
    v.push_back(3);
    v.push_back(5);
    v.push_back(737);
    v.push_back(0);
    std::vector<int>::iterator it2 = v.begin();
    std::vector<int>::iterator ite2 = v.end();
    
    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }
    
    std::cout << "\033[36m" << "-----------------------" << "\033[0m" << std::endl;
    std::cout << "\033[34m" << "------TEST DEQUE-------" << "\033[0m" << std::endl;
    std::deque<int> d;
    d.push_back(5);
    d.push_back(17);
    
    std::cout << "DERNIER ELEMENT AJOUTE: " << std::endl;
    std::cout << d.back() << std::endl;
    
    std::cout << "TAILLE DU DEQUE: " << std::endl;
    d.pop_back();
    std::cout << d.size() << std::endl;

    std::cout << "CONTENU DU DEQUE:" << std::endl;
    d.push_back(3);
    d.push_back(5);
    d.push_back(737);
    d.push_back(0);
    std::deque<int>::iterator it3 = d.begin();
    std::deque<int>::iterator ite3 = d.end();
    
    while (it3 != ite3)
    {
        std::cout << *it3 << std::endl;
        ++it3;
    }
    std::cout << "\033[34m" << "------------------------" << "\033[0m" << std::endl;
    return (0);
}

