/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:15:40 by migupere          #+#    #+#             */
/*   Updated: 2025/01/10 21:40:59 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 5);
        ShrubberyCreationForm formA("home");
		std::cout << formA << std::endl;
        bob.signForm(formA);
        bob.executeForm(formA);

        RobotomyRequestForm formB("target");
        bob.signForm(formB);
        bob.executeForm(formB);

        PresidentialPardonForm formC("Alice");
        bob.signForm(formC);
        bob.executeForm(formC);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
