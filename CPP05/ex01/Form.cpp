/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:33:02 by migupere          #+#    #+#             */
/*   Updated: 2025/01/09 13:38:06 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::~Form(){}

Form::Form(Form const & src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute){
	*this = src;
}

Form & Form::operator=(Form const & src){
	if (this != &src){
		_signed = src._signed;
	}
	return *this;
}

std::string Form::getName() const{
	return _name;
}

bool Form::getSigned() const{
	return _signed;
}

int Form::getGradeToSign() const{
	return _gradeToSign;
}

int Form::getGradeToExecute() const{
	return _gradeToExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat){
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooHighException();
	_signed = true;
}

const char* Form::GradeTooHighException::what() const throw(){
	return "Form grade is too high";
}

const char* Form::GradeTooLowException::what() const throw(){
	return "Form grade is too low";
}

std::ostream & operator<<(std::ostream & o, Form const & src){
	o << "Form " << src.getName() << ", signed: " << (src.getSigned() ? "yes" : "no")
        << ", grade to sign: " << src.getGradeToSign()
        << ", grade to execute: " << src.getGradeToExecute();
	return o;
}