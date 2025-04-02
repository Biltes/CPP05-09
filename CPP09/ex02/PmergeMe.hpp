/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:56:04 by migupere          #+#    #+#             */
/*   Updated: 2025/03/31 15:11:13 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <string>
#include <ctime>
#include <limits>
#include <stdexcept>

class PmergeMe {
private:
    std::vector<int> _vec;
    std::deque<int> _deq;

    std::vector<size_t> generateJacobsthalSequence(size_t n);
    
    std::vector<size_t> expandJacobsthalIndices(size_t n);

    template <typename T>
    struct PairComparator {
        bool operator()(const std::pair<T, T>& a, const std::pair<T, T>& b) const {
            return a.first < b.first;
        }
    };
    
    template <typename T>
    void FordJohnson(T &c);

public:
    PmergeMe();
    ~PmergeMe();
    
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    
    void checkInput(char **av);
    
    void print(char **input);
};

template <typename T>
void PmergeMe::FordJohnson(T &c) {
    if (c.size() <= 1) return;

    if (c.size() == 2) {
        if (c[0] > c[1]) {
            typename T::value_type temp = c[0];
            c[0] = c[1];
            c[1] = temp;
        }
        return;
    }

    typename T::value_type oddElement;
    bool hasOddElement = false;
    
    if (c.size() % 2 != 0) {
        hasOddElement = true;
        oddElement = c[c.size() - 1];
        c.pop_back();
    }

    std::vector<std::pair<typename T::value_type, typename T::value_type> > pairs;
    for (size_t i = 0; i < c.size(); i += 2) {
        if (c[i] > c[i + 1]) {
            pairs.push_back(std::make_pair(c[i], c[i + 1]));
        } else {
            pairs.push_back(std::make_pair(c[i + 1], c[i]));
        }
    }
    
    std::sort(pairs.begin(), pairs.end(), PairComparator<typename T::value_type>());

    T mainChain;
    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].first);
    }

    T pend;
    for (size_t i = 0; i < pairs.size(); i++) {
        pend.push_back(pairs[i].second);
    }

	FordJohnson(mainChain);

    c.clear();
    for (size_t i = 0; i < mainChain.size(); i++) {
        c.push_back(mainChain[i]);
    }

    if (!pend.empty()) {
        typename T::iterator pos = std::lower_bound(c.begin(), c.end(), pend[0]);
        c.insert(pos, pend[0]);
    }

    if (pend.size() > 1) {
        std::vector<size_t> insertOrder = expandJacobsthalIndices(pend.size());

        for (size_t i = 0; i < insertOrder.size(); i++) {
            size_t idx = insertOrder[i];
            if (idx < pend.size() && idx > 0) {
                typename T::iterator pos = std::lower_bound(c.begin(), c.end(), pend[idx]);
                c.insert(pos, pend[idx]);
            }
        }
    }

    if (hasOddElement) {
        typename T::iterator pos = std::lower_bound(c.begin(), c.end(), oddElement);
        c.insert(pos, oddElement);
    }
}