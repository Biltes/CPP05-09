/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:23:58 by migupere          #+#    #+#             */
/*   Updated: 2025/03/12 15:00:41 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Error: Usage: ./btc <input_file>" << std::endl;
        return 1;
    }
    
    BitcoinExchange btc;
    btc.processInputFile(argv[1]);
    
    return 0;
}