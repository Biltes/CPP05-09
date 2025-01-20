/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:29:08 by migupere          #+#    #+#             */
/*   Updated: 2025/01/10 16:23:17 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target){
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src){
	*this = src;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & src){
	if (this != &src)
		this->_target = src._target;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	try {
		if (executor.getGrade() > getGradeToExecute())
			throw AForm::GradeTooHighException();
		else if (!getSigned())
			throw AForm::FormNotSignedException();
		else{
			std::cout << "*drilling noises*" << std::endl;
			srand(static_cast<unsigned>(time(0)) ^ getpid());
			if (rand() % 2)
				std::cout << _target << " has been robotomized successfully" << std::endl;
			else
				std::cout << _target << " robotomization failed" << std::endl;
		}
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}
}