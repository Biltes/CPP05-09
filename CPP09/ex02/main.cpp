#include "PmergeMe.hpp"
#include <cstdlib>

int main(int argc, char **argv) {

	PmergeMe Fjhonson;

    if (argc < 3) {
        std::cerr << "Usage: ./PmergeMe <sequence of positive integers>" << std::endl;
        return 1;
    }

	Fjhonson.FordJohnson(argc, argv);

    return 0;
}