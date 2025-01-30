/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:56:55 by migupere          #+#    #+#             */
/*   Updated: 2025/01/28 16:45:55 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
    try {
        Array<int> emptyArray;
        std::cout << "Size of empty array: " << emptyArray.size() << std::endl;

        Array<int> intArray(5);
        std::cout << "Size of integer array: " << intArray.size() << std::endl;

        for (unsigned int i = 0; i < intArray.size(); ++i) {
            std::cout << "Element " << i << ": " << intArray[i] << std::endl;
        }

        for (unsigned int i = 0; i < intArray.size(); ++i) {
            intArray[i] = i * 10;
        }
        std::cout << "After modification:\n";
        for (unsigned int i = 0; i < intArray.size(); ++i) {
            std::cout << "Element " << i << ": " << intArray[i] << std::endl;
        }

        Array<int> copyArray(intArray);
        std::cout << "Copied array:\n";
        for (unsigned int i = 0; i < copyArray.size(); ++i) {
            std::cout << "Element " << i << ": " << copyArray[i] << std::endl;
        }

        Array<int> assignedArray;
        assignedArray = intArray;
        std::cout << "Assigned array:\n";
        for (unsigned int i = 0; i < assignedArray.size(); ++i) {
            std::cout << "Element " << i << ": " << assignedArray[i] << std::endl;;
        }

        std::cout << "Accessing out-of-bounds index:\n";
        std::cout << intArray[10] << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
