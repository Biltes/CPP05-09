/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:33:02 by migupere          #+#    #+#             */
/*   Updated: 2025/01/07 17:31:15 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm(){}

AForm::AForm(AForm const & src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute){
	*this = src;
}

AForm & AForm::operator=(AForm const & src){
	if (this != &src){
		_signed = src._signed;
	}
	return *this;
}

std::string AForm::getName() const{
	return _name;
}

bool AForm::getSigned() const{
	return _signed;
}

int AForm::getGradeToSign() const{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const{
	return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat){
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooHighException();
	_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw(){
	return "AForm grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw(){
	return "AForm grade is too low";
}

std::ostream & operator<<(std::ostream & o, AForm const & src){
	o << "AForm " << src.getName() << ", signed: " << (src.getSigned() ? "yes" : "no")
        << ", grade to sign: " << src.getGradeToSign()
        << ", grade to execute: " << src.getGradeToExecute();
	return o;
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}
