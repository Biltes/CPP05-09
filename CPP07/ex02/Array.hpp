#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <class T> class Array {
private:
	T *elm;
	unsigned int sz;
public:
	Array();
	Array(unsigned int num);
	Array(const Array& cpy);
	Array &operator=(const Array& cpy);
	T &operator[](unsigned int i);
	~Array();

	unsigned int size();

	class OutOfBoundsE : public std::exception {
	public:
		virtual const char * what() const throw();
	};
};

#include "Array.tpp"

#endif //ARRAY_HPP