#include "iter.hpp"

int main() {
	std::string arr[] = { "abc", "def", "ghi", "jkl" };
	size_t len = sizeof(arr) / sizeof(arr[0]);
	iter(arr, len, print);
	std::cout << std::endl;

	int arr2[] = { 0, 1, 2, 3 };
	size_t l = 4;
	iter(arr2, l, print);
	std::cout << std::endl;
}
