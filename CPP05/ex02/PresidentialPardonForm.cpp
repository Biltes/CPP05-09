/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:23:31 by migupere          #+#    #+#             */
/*   Updated: 2025/01/10 17:27:43 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target){
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm(src){
	*this = src;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & src){
	if (this != &src)
		this->_target = src._target;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	try
	{
		if (executor.getGrade() > getGradeToExecute())
			throw AForm::GradeTooHighException();
		else if (!getSigned())
			throw AForm::FormNotSignedException();
		else
			std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
