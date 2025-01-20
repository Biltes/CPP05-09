/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:06:37 by migupere          #+#    #+#             */
/*   Updated: 2025/01/07 16:38:06 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade){
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name), _grade(src._grade){
	*this = src;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src){
	if (this != &src){
		_grade = src._grade;
	}
	return *this;
}

std::string Bureaucrat::getName() const{
	return _name;
}

int Bureaucrat::getGrade() const{
	return _grade;
}

void Bureaucrat::incrementGrade(){
	try{
		if (_grade - 1 < 1)
			throw Bureaucrat::GradeTooHighException();
		_grade--;
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}
}

void Bureaucrat::decrementGrade(){
	try{
		if (_grade + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
		_grade++;
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade is too low";
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & src){
	o << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return o;
}
