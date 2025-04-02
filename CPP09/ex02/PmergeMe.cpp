/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:28:38 by migupere          #+#    #+#             */
/*   Updated: 2025/03/31 14:25:54 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}

std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n) {
    std::vector<size_t> sequence;
    sequence.push_back(0);
    sequence.push_back(1);
    
    size_t i = 2;
    while (sequence[i-1] < n) {
        sequence.push_back(sequence[i-1] + 2 * sequence[i-2]);
        i++;
    }
    return sequence;
}


std::vector<size_t> PmergeMe::expandJacobsthalIndices(size_t n) {
    if (n <= 1) return std::vector<size_t>();
    
    std::vector<size_t> jacobsthal = generateJacobsthalSequence(n);
    std::vector<size_t> indices;
    std::vector<bool> used(n, false);

    if (n > 1) {
        indices.push_back(1);
        used[1] = true;
    }

    for (size_t i = 2; i < jacobsthal.size() && jacobsthal[i] <= n; ++i) {
        for (size_t j = jacobsthal[i] < n ? jacobsthal[i] : n; j > jacobsthal[i-1]; --j) {
            if (j < n && !used[j]) {
                indices.push_back(j);
                used[j] = true;
            }
        }
    }

    for (size_t i = 1; i < n; ++i) {
        if (!used[i]) {
            indices.push_back(i);
        }
    }
    
    return indices;
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
        if (num > std::numeric_limits<int>::max() || num <= 0) {
            throw std::invalid_argument("Invalid input");
        }
        _vec.push_back(static_cast<int>(num));
        _deq.push_back(static_cast<int>(num));
        i++;
    }
}

void PmergeMe::print(char **input) {
    std::cout << "Before: ";
    int i = 1;
    while (input[i]) {
        std::cout << input[i];
        if (input[i + 1])
            std::cout << " ";
        i++;
    }
    std::cout << std::endl;

    clock_t vecstart = clock();
    FordJohnson(_vec);
    clock_t vecend = clock();
    
    clock_t deqstart = clock();
    FordJohnson(_deq);
    clock_t deqend = clock();
    
    double vecduration = static_cast<double>(vecend - vecstart) * 1e6 / CLOCKS_PER_SEC;
    double deqduration = static_cast<double>(deqend - deqstart) * 1e6 / CLOCKS_PER_SEC;

    std::cout << "After: ";
    for (size_t i = 0; i < _vec.size(); i++) {
        std::cout << _vec[i];
        if (i + 1 < _vec.size())
            std::cout << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << _vec.size()
        << " elements with std::vector : " << vecduration << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size()
        << " elements with std::deque : " << deqduration << " us" << std::endl;
}