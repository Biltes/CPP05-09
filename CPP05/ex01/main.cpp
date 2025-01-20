/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:15:40 by migupere          #+#    #+#             */
/*   Updated: 2025/01/08 15:57:27 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main(){
    try {
        Bureaucrat alice("Alice", 42);
		Bureaucrat bob("Bob", 150);
        Form form("contract", 50, 25);
		Form a("test", 149, 145);
		
        std::cout << form << std::endl;
        alice.signForm(form);
        std::cout << form << std::endl;

        bob.signForm(form);
		bob.signForm(a);
		bob.decrementGrade();
		std::cout << bob;
		bob.incrementGrade();
		std::cout << bob;
		bob.signForm(a);
		std::cout << a << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}


// int main()
// {
//     try 
//     {
//         Bureaucrat valid("valid", 100);
//         Form Formula("Formula", 90, 110);
//         Form test("teste", 150, 145);
//         std::cout << Formula << std::endl;
//         valid.signForm(Formula);
//         std::cout << Formula << std::endl;
//         valid.signForm(test);
//         std::cout << test << std::endl;
//         valid.decrementGrade();
//         std::cout << valid;
//     } 
//     catch (const std::exception& e) 
//     {
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }

// }
