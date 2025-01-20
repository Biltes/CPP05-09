/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:06:37 by migupere          #+#    #+#             */
/*   Updated: 2025/01/10 21:41:50 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class AForm;

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

void Bureaucrat::executeForm(AForm const &form) const{
	try {
		if (_grade > form.getGradeToExecute())
			throw AForm::GradeTooHighException();
		if (!form.getSigned())
			throw AForm::FormNotSignedException();
		std::cout << _name << " executed " << form.getName() << std::endl;
		form.execute(*this);
	} 
	catch (std::exception &e) {
		std::cout << _name << " couldn't execute " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::signForm(AForm &form){
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    } 
	catch (std::exception &e) {
        std::cout << _name << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & src){
	o << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return o;
}
