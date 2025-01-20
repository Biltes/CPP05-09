/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:15:40 by migupere          #+#    #+#             */
/*   Updated: 2025/01/10 21:43:16 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main() {
    Intern someRandomIntern;
    AForm* form = NULL;

    try {
        form = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
        if (form) {
            Bureaucrat bob("Bob", 5);
            bob.signForm(*form);
            bob.executeForm(*form);
            delete form;
        }

        form = someRandomIntern.makeForm("ShrubberyCreationForm", "Home");
        if (form) {
            Bureaucrat bob("Bob", 150);
            bob.signForm(*form);
            bob.executeForm(*form);
            delete form;
        }

        form = someRandomIntern.makeForm("PresidentialPardonForm", "Home");
        if (form) {
            Bureaucrat bob("Bob", 5);
            bob.signForm(*form);
            bob.executeForm(*form);
            delete form;
        }

        form = someRandomIntern.makeForm("invalid form", "Target");
        if (form) {
            delete form;
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}

