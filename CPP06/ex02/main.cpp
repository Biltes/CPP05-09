/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:28:37 by migupere          #+#    #+#             */
/*   Updated: 2025/01/23 14:33:09 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <iostream>
#include <cstdlib>

Base * generate(void){
	std::srand((unsigned)time(NULL));
	int random = rand() % 3;
	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

void identify(Base * p){
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p){
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	return ;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	return ;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cout << "Unknown type" << std::endl;
	}
}

int main(){
	Base* base = generate();
	
	std::cout << "Pointer: ";
	identify(base);
	std::cout << "Reference: ";
	identify(*base);
	delete base;
	return 0;
}