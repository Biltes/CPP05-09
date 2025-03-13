/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:24:26 by migupere          #+#    #+#             */
/*   Updated: 2025/03/12 14:35:16 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <stdexcept>

class RPN
{
	public:
		RPN();
		RPN(RPN const &other);
		RPN &operator=(RPN const &other);
		~RPN();

		static int evaluate(const std::string &expr);
};