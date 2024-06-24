/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:25:29 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/24 15:34:51 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data originalData;
    originalData.number = 42;
    originalData.text = "Example text";

    // Sérialise l'objet Data.
    uintptr_t serialized = Serializer::serialize(&originalData);
    std::cout << "Serialized data: " << serialized << std::endl;

    // Désérialise l'objet Data.
    Data *deserializedData = Serializer::deserialize(serialized);
    std::cout << "Deserialized data: " << deserializedData->number << " and " << deserializedData->text << std::endl;

    // Vérifie que les données désérialisées correspondent à l'original.
    if (deserializedData == &originalData)
        std::cout << "Deserialization is successful." << std::endl;
	else
        std::cout << "Deserialization failed." << std::endl;
   
	// Test avec un décalage d'adresse pour vérifier la robustesse
    std::cout << "Testing with offset address:" << std::endl;
    uintptr_t offsetSerialized = serialized + sizeof(int);
    Data *offsetDeserializedData = Serializer::deserialize(offsetSerialized);

    // Cela devrait échouer car le pointeur désérialisé ne correspond pas à l'adresse d'origine.
    if (offsetDeserializedData == &originalData)
        std::cout << "Offset deserialization incorrectly succeeded." << std::endl;
    else
        std::cout << "Offset deserialization correctly failed." << std::endl;

    // Test de désérialisation d'un pointeur nul
    std::cout << "Testing with null pointer:" << std::endl;
    uintptr_t nullSerialized = Serializer::serialize(NULL);
    Data* nullDeserializedData = Serializer::deserialize(nullSerialized);

    // Cela devrait réussir car un pointeur nul reste un pointeur nul après sérialisation/désérialisation.
    if (nullDeserializedData == NULL)
        std::cout << "Null pointer deserialization is successful." << std::endl;
    else
        std::cout << "Null pointer deserialization failed." << std::endl;
    return (0);
}