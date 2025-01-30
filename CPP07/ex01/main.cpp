/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:44:52 by migupere          #+#    #+#             */
/*   Updated: 2025/01/28 14:48:22 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void print(T const &x)
{
	std::cout << x << std::endl;
}
int main() {
	int tab[] = { 0, 1, 2, 3, 4 };
	::iter(tab, 5, print);
	std::string tab2[] = { "Hello", "mr.", "President" };
	::iter(tab2, 3, print);
	return 0;
}
