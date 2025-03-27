/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:28:48 by migupere          #+#    #+#             */
/*   Updated: 2025/03/27 15:18:14 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Usage: ./pmergme [input]" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe m(av);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what()  << std::endl;
	}
	return (0);
}