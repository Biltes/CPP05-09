/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:56:04 by migupere          #+#    #+#             */
/*   Updated: 2025/03/19 16:09:28 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <algorithm>
# include <cmath>
# include <cstdio>
# include <deque>
# include <iostream>
# include <list>
# include <sstream>
# include <string>
# include <vector>
# include <ctime>
# include <iomanip>

class PmergeMe
{
private:
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);

    std::list<int> _list;
    std::deque<int> _deque;
    std::vector<int> _jacobsthalNumbers;
    std::vector<int> _insertion;
    double _elapsedDeque;
    double _elapsedList;

    bool _validNumber(const std::string &expression);

public:
    PmergeMe(void);
    ~PmergeMe(void);
    void mergeSortDeque(std::deque<int> &mainSet);
    void mergeSortList(std::list<int> &list);
    void insertPendingElements(std::deque<int> &mainSet, std::deque<int> &pendingSet);
    void generateJacobstal(unsigned long n);
    void insertionIndexWithJacobsthal(unsigned long size);
    std::deque<int> createMainAndPendingSet(std::deque<int> &mainSet, std::deque<int> &array);
    std::list<int> createMainAndPendingSet(std::list<int> &mainSet, std::list<int> &array);
    void insertPendingElements(std::list<int> &mainSet, std::list<int> &pendingSet);
    std::list<int>::iterator advanceIterator(std::list<int>::iterator it, size_t n);

    void FordJohnson(int argc, char **argv);
};
