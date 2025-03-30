/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:28:48 by migupere          #+#    #+#             */
/*   Updated: 2025/03/30 16:06:55 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Error: No arguments provided" << std::endl;
        return 1;
    }
    
    try {
        PmergeMe sorter;
        sorter.checkInput(av);
        sorter.print(av);
    } catch (const std::exception &e) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    return 0;
}