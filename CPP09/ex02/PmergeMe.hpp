/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:56:04 by migupere          #+#    #+#             */
/*   Updated: 2025/03/27 15:20:19 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <algorithm>
# include <cmath>
# include <cstdio>
# include <deque>
# include <iostream>
# include <limits>
# include <sstream>
# include <string>
# include <vector>
# include <ctime>
# include <iomanip>

class PmergeMe
{
	private:
			std::vector<int> _vec;
			std::deque<int> _deq;
			
			std::vector<size_t> generateJacobsthalSequence(size_t n);
		
			template <typename T>
			void mergeSort(T &c, const T &left, const T &right);
		
			template <typename T>
			void insertionSort(T &c);
		
			template <typename T>
			void FordJohnson(T &c);
	public:
			PmergeMe();
			PmergeMe(char **input);
			PmergeMe(const PmergeMe &other);
			PmergeMe &operator=(const PmergeMe &other);
			~PmergeMe();

			void checkInput(char **av);
			void print(char **input);
		
};
