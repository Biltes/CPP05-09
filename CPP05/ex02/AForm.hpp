/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:21:14 by migupere          #+#    #+#             */
/*   Updated: 2025/01/07 19:00:10 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM
#define AFORM

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
	private:
		std::string const _name;
		bool _signed;
		int const _gradeToSign;
		int const _gradeToExecute;
	public:
		AForm(const std::string name, int gradeToSign, int gradeToExecute);
		~AForm();
		AForm(AForm const & src);
		AForm & operator=(AForm const & src);
		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;	
		
		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class FormNotSignedException : public std::exception {
        	virtual const char* what() const throw();
    	};
};

std::ostream & operator<<(std::ostream & o, AForm const & src);

#endif