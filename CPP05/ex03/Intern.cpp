/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:48:24 by migupere          #+#    #+#             */
/*   Updated: 2025/01/10 21:30:43 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){
}

Intern::Intern(Intern const & src){
	*this = src;
}

Intern & Intern::operator=(Intern const & src){
	(void)src;
	return *this;
}

AForm *Intern::makeForm(const std::string formName, const std::string target) {
	std::string forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	for (int i = 0; i < 3; i++) {
		if (formName == forms[i]) {
			AForm *form = NULL;
			switch (i) {
				case 0:
					form = new ShrubberyCreationForm(target);
					break;
				case 1:
					form = new RobotomyRequestForm(target);
					break;
				case 2:
					form = new PresidentialPardonForm(target);
					break;
			}
			std::cout << "Intern creates " << formName << std::endl;
			return form;
		}
	}
	std::cout << "Intern can't create " << formName << std::endl;
    return NULL;
}
