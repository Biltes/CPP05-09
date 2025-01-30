/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:25:41 by migupere          #+#    #+#             */
/*   Updated: 2025/01/30 17:03:39 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
	  try {
        Span sp(5);
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		
        sp.addNumber(42);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
	
    try {
        Span emptySpan(3);
        emptySpan.shortestSpan();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
	
	    try {
        Span emptySpan(3);
        emptySpan.shortestSpan();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Span oneNumberSpan(3);
        oneNumberSpan.addNumber(10);
        oneNumberSpan.shortestSpan();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Span sp2(2);
        sp2.addNumber(10);
        sp2.addNumber(20);
        sp2.addNumber(30);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Span sp3(100000);
        for (int i = 0; i < 100000; ++i) {
            sp3.addNumber(i);
        }
        std::cout << "Shortest Span (many numbers): " << sp3.shortestSpan() << std::endl;
        std::cout << "Longest Span (many numbers): " << sp3.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}