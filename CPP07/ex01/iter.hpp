#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void iter(T* arr, int len, void (*print)(T&)) {
	for (int i = 0; i < len; ++i) {
		print(arr[i]);
	}
}

template<typename T>
void print(T& elem){
	std::cout << elem;
}

#endif //ITER_HPP
