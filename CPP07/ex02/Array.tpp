// TEMPLATE
#include "Array.hpp" // REMOVE

template <typename T>
Array<T>::Array() : sz(0) {
	elm = new T[sz];
}

template <typename T>
Array<T>::Array(unsigned int num) : sz(num) {
	if (num > 2147483647)
		throw Array::OutOfBoundsE();
	elm = new T[num];
	for (unsigned int i = 0; i < num; i++) {
		elm[i] = T();
	}
}

template<class T>
Array<T>::Array(const Array<T> &cpy) {
	sz = cpy.sz;
	elm = new T[sz];
	for (unsigned int i = 0; i < sz; i++)
		elm[i] = cpy.elm[i];
}

template<class T>
Array<T> &Array<T>::operator=(const Array<T> &cpy) {
	if (this != cpy)
	{
		sz = cpy.sz;
		elm = new T[sz];
		for (unsigned int i = 0; i < sz; i++)
			elm[i] = cpy.elm[i];
	}
	return *this;
}

template<class T>
T &Array<T>::operator[](unsigned int i) {
	if (i >= sz)
		throw OutOfBoundsE();
	return elm[i];
}

template <class T>
Array<T>::~Array()
{
	if (elm)
		delete[] elm;
}

template<class T>
unsigned int Array<T>::size() {
	return this->sz;
}

template<class T>
const char *Array<T>::OutOfBoundsE::what() const throw() {
	return  "Index out of bounds!";
}
