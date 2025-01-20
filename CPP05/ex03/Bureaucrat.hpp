/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:55:59 by migupere          #+#    #+#             */
/*   Updated: 2025/01/09 16:23:53 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAuCRAT
#define BUREAuCRAT

#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include <cstdlib> 
#include <ctime>
#include <unistd.h>

class AForm;

class Bureaucrat{
	private:
		std::string const _name;
		int _grade;
	public:
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(Bureaucrat const & src);
		Bureaucrat & operator=(Bureaucrat const & src);
		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void executeForm(AForm const &form) const;
		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		void signForm(AForm &form);
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & src);

#endif