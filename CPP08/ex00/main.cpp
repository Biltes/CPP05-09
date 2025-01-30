/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:00:07 by migupere          #+#    #+#             */
/*   Updated: 2025/01/30 14:50:17 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iterator>

// int main()
// {
// 	std::vector<int> v;
// 	v.push_back(1);
// 	v.push_back(2);
// 	v.push_back(3);
// 	v.push_back(4);
// 	v.push_back(5);
// 	try
// 	{
// 		std::cout << easyfind(v, 3) << std::endl;
// 		std::cout << easyfind(v, 5) << std::endl;
// 		std::cout << easyfind(v, 42) << std::endl;
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << "Value not found" << std::endl;
// 	}
// 	return 0;
// }


#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

void testVector() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);

    try {
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "Found: " << *it << " at position " 
                  << std::distance(vec.begin(), it) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void testList() {
    std::list<int> lst;
    lst.push_back(100);
    lst.push_back(200);
    lst.push_back(300);
    lst.push_back(400);

    try {
        std::list<int>::iterator it = easyfind(lst, 500);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void testDeque() {
    std::deque<int> deq;
    deq.push_back(5);
    deq.push_back(10);
    deq.push_back(15);
    deq.push_back(20);
    deq.push_back(25);

    try {
        std::deque<int>::iterator it = easyfind(deq, 25);
        std::cout << "Found: " << *it << " at position " 
                  << std::distance(deq.begin(), it) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

int main() {
    std::cout << "Testing with vector:" << std::endl;
    testVector();
    
    std::cout << "\nTesting with list:" << std::endl;
    testList();
    
    std::cout << "\nTesting with deque:" << std::endl;
    testDeque();
    
    return 0;
}

