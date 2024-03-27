/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:00:20 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/27 15:02:04 by juandrie         ###   ########.fr       */
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
    
    std::cout << "Affiche le dernier element ajoute: " << mstack.top() << std::endl;
    mstack.pop();
    
    std::cout << "Affiche la taille de la stack: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    
    return (0);
}


// int main()
// {
//     std::list<int> lst;
//     lst.push_back(5);
//     lst.push_back(17);
    
//     std::cout << "Affiche le dernier element ajoute: " << lst.back() << std::endl;
//     lst.pop_back();
    
//     std::cout << "Affiche la taille de la stack: " << lst.size() << std::endl;
//     lst.push_back(3);
//     lst.push_back(5);
//     lst.push_back(737);
//     lst.push_back(0);
//     std::list<int>::iterator it = lst.begin();
//     std::list<int>::iterator ite = lst.end();
    
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }
    
//     return (0);
// }

// int main()
// {
//     std::vector<int> v;
//     v.push_back(5);
//     v.push_back(17);
    
//     std::cout << "Affiche le dernier element ajoute: " << v.back() << std::endl;
//     v.pop_back();
    
//     std::cout << "Affiche la taille de la stack: " << v.size() << std::endl;
//     v.push_back(3);
//     v.push_back(5);
//     v.push_back(737);
//     v.push_back(0);
//     std::vector<int>::iterator it = v.begin();
//     std::vector<int>::iterator ite = v.end();
    
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }
    
//     return (0);
// }

// int main()
// {
//     std::deque<int> d;
//     d.push_back(5);
//     d.push_back(17);
    
//     std::cout << "Affiche le dernier element ajoute: " << d.back() << std::endl;
//     d.pop_back();
    
//     std::cout << "Affiche la taille de la stack: " << d.size() << std::endl;
//     d.push_back(3);
//     d.push_back(5);
//     d.push_back(737);
//     d.push_back(0);
//     std::deque<int>::iterator it = d.begin();
//     std::deque<int>::iterator ite = d.end();
    
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }
    
//     return (0);
// }