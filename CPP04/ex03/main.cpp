/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:10:56 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/13 19:24:35 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"


// int main()
// {
//     IMateriaSource *src = new MateriaSource();
    
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());

    
//     ICharacter *me = new Character("me");
    
//     AMateria *tmp;
    
//     tmp = src->createMateria("ice");

//     me->equip(tmp);
    
//     tmp = src->createMateria("cure");
    
//     me->equip(tmp);
    
//     ICharacter* bob = new Character("bob");
    
//     me->use(0, *bob);
//     me->use(1, *bob);
    
//     delete bob;
//     delete me;
//     delete src;
    
//     return 0;
// }

int main()
{
    // Création et apprentissage de matéria
    MateriaSource *source = new MateriaSource();
    source->learnMateria(new Ice());
    source->learnMateria(new Cure());

    // Création de personnages
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");

    // Création et équipement de matéria à partir de la source
    AMateria* tmp;
    tmp = source->createMateria("ice");
    me->equip(tmp);
    tmp = source->createMateria("cure");
    me->equip(tmp);

    // Utilisation des matéria sur bob
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob); // Test avec un index vide/inutilisé

    // Test d'équipement supplémentaire (devrait échouer car seulement 4 emplacements)
    tmp = source->createMateria("ice");
    me->equip(tmp); // Le 5ème équipement, ne devrait pas avoir d'effet

    // Test d'unicité - même type mais objets distincts
    AMateria* uniqueIce = new Ice();
    me->equip(uniqueIce); // Doit équiper si un emplacement est disponible

    // Déséquipement et vérification de fuite de mémoire
    me->unequip(0); // tmp est déséquipé mais pas supprimé

    // Nettoyage
    delete bob;
    delete me;
    delete source;

    // Note: Assurez-vous de supprimer les matéria non équipées ou déséquipées pour éviter les fuites de mémoire
    //delete tmp; // tmp créé mais jamais équipé ou déséquipé après le plein
    // delete uniqueIce; // Si jamais équipé

    return 0;
}