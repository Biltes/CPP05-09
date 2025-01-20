/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:15:40 by migupere          #+#    #+#             */
/*   Updated: 2025/01/07 14:37:40 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(){
	try{
		Bureaucrat miguel("Miguel", 151);
		std::cout << miguel;
		miguel.decrementGrade();
		std::cout << miguel;
		miguel.decrementGrade();
		std::cout << miguel;
		std::cout << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}
	try{
		Bureaucrat biltes("Biltes", 2);
		Bureaucrat biltes2("Biltes2", 150);
		std::cout << biltes;
		biltes.incrementGrade();
		std::cout << biltes;
		biltes.incrementGrade();
		std::cout << biltes;
		biltes2.incrementGrade();
		std::cout << biltes2;
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}
}