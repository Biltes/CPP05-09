/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:52:33 by migupere          #+#    #+#             */
/*   Updated: 2025/01/30 16:19:49 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span {
	private:
		unsigned int _N;
		std::vector<int> _vec;
	public:
		Span(unsigned int N);
		Span(const Span &src);
		~Span();
		Span &operator=(const Span &src);

		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		
		class FullSpanException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		
		class NoSpanException : public std::exception {
			public:
				virtual const char *what() const throw();
		};	
};

#endif
