/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:11:36 by migupere          #+#    #+#             */
/*   Updated: 2025/01/23 14:18:41 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main() {
    Data originalData = {42, "Hello, World!"};

	std::cout << "Original data: " << originalData.n << " " << originalData.text << std::endl;

    uintptr_t raw = Serializer::serialize(&originalData);

	std::cout << "Serialized data: " << raw << std::endl;
	//raw++;

    Data* deserializedData = Serializer::deserialize(raw);

	std::cout << "Deserialized data: " << deserializedData << std::endl;
    if (deserializedData == &originalData) {
        std::cout << "Serialization and deserialization successful!\n";
        std::cout << "Number: " << deserializedData->n << "\n";
        std::cout << "Text: " << deserializedData->text << "\n";
    } else {
        std::cout << "Serialization and deserialization failed!\n";
    }

    return 0;
}
