/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:28:38 by migupere          #+#    #+#             */
/*   Updated: 2025/03/27 16:00:13 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(char **input) {
	checkInput(input);
	print(input);
}
PmergeMe::PmergeMe(const PmergeMe &other) {*this = other;}
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {(void)other; return *this;}
PmergeMe::~PmergeMe() {}

std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n) {
    std::vector<size_t> sequence;
    size_t a = 0, b = 1;
    while (b < n) {
        sequence.push_back(b);
        size_t next = a + 2 * b;
        a = b;
        b = next;
    }
    return sequence;
}

template <typename T>
void PmergeMe::mergeSort(T &c, const T &left, const T &right) {
    c.clear();
    size_t i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j])
            c.push_back(left[i++]);
        else
            c.push_back(right[j++]);
    }
    while (i < left.size())
        c.push_back(left[i++]);
    while (j < right.size())
        c.push_back(right[j++]);
}

template <typename T>
void PmergeMe::insertionSort(T &c) {
    for (size_t i = 1; i < c.size(); ++i) {
        typename T::value_type key = c[i];
        int j = i - 1;
        while (j >= 0 && c[j] > key) {
            c[j + 1] = c[j];
            j--;
        }
        c[j + 1] = key;
    }
}

template <typename T>
void PmergeMe::FordJohnson(T &c) {
    if (c.size() <= 1)
        return;

    if (c.size() == 2) {
        if (c[0] > c[1])
            std::swap(c[0], c[1]);
        return;
    }

    if (c.size() <= 16) {
        insertionSort(c);
        return;
    }

    T left(c.begin(), c.begin() + c.size() / 2);
    T right(c.begin() + c.size() / 2, c.end());

    FordJohnson(left);
    FordJohnson(right);

    T temp;
    mergeSort(temp, left, right);

    std::vector<size_t> jacobsthal = generateJacobsthalSequence(temp.size());
    c.clear();

    for (size_t i = 0; i < jacobsthal.size(); ++i) {
        if (jacobsthal[i] < temp.size())
            c.push_back(temp[jacobsthal[i]]);
    }

    for (size_t i = 0; i < temp.size(); ++i) {
        if (std::find(jacobsthal.begin(), jacobsthal.end(), i) == jacobsthal.end())
            c.push_back(temp[i]);
    }
}

void PmergeMe::checkInput(char **av) {
    int i = 1;
    while (av[i]) {
        std::string str(av[i]);
        for (size_t j = 0; j < str.size(); j++) {
            if (!isdigit(str[j])) {
                throw std::invalid_argument("Invalid input");
            }
        }
        long num = std::strtol(str.c_str(), NULL, 10);
        if (num > std::numeric_limits<int>::max())
            throw std::invalid_argument("Invalid input");
        _vec.push_back(num);
        _deq.push_back(num);
        i++;
    }
}

void PmergeMe::print(char **input) {
    clock_t vecstart = clock();
    FordJohnson(_vec);
    clock_t vecend = clock();
    clock_t deqstart = clock();
    FordJohnson(_deq);
    clock_t deqend = clock();
    double vecduration = (double)(vecend - vecstart) * 1e6 / CLOCKS_PER_SEC;
    double deqduration = (double)(deqend - deqstart) * 1e6 / CLOCKS_PER_SEC;

    std::cout << "Before : ";
    for (int i = 1; input[i]; i++) {
        std::cout << input[i];
        if (input[i + 1])
            std::cout << " ";
    }
    std::cout << std::endl;

    std::cout << "After  : ";
    for (size_t i = 0; i < _vec.size(); i++) {
        std::cout << _vec[i];
        if (i + 1 < _vec.size())
            std::cout << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _vec.size() 
              << " elements with std::vector : " << vecduration << " µs" << std::endl;

    std::cout << "Time to process a range of " << _deq.size() 
              << " elements with std::deque  : " << deqduration << " µs" << std::endl;
}