/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:16:46 by migupere          #+#    #+#             */
/*   Updated: 2025/01/30 16:56:39 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &src) {
	*this = src;
}

Span::~Span() {}

Span &Span::operator=(const Span &src) {
	if (this != &src) {
		_N = src._N;
		_vec = src._vec;
	}
	return *this;
}

void Span::addNumber(int n) {
	try {
		if (_vec.size() == _N)
			throw FullSpanException();
		_vec.push_back(n);
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

int Span::shortestSpan() {
	if (_vec.size() < 2)
		throw NoSpanException();
	std::vector<int> tmp = _vec;
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (size_t i = 1; i < tmp.size() - 1; i++) {
		min = std::min(min, tmp[i + 1] - tmp[i]);
	}
	return min;
}

int Span::longestSpan() {
	if (_vec.size() < 2)
		throw NoSpanException();
	int min = *std::min_element(_vec.begin(), _vec.end());
	int max = *std::max_element(_vec.begin(), _vec.end());
	return max - min;
}

const char *Span::FullSpanException::what() const throw() {
	return "Span is already full";
}

const char *Span::NoSpanException::what() const throw() {
	return "Not enough numbers to find Span";
}
