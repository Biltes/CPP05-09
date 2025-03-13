/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:35:20 by migupere          #+#    #+#             */
/*   Updated: 2025/03/12 15:31:55 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) {
	*this = other;
}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other) {
		(void)other;
	}
	return *this;
}

RPN::~RPN() {}

int RPN::evaluate(const std::string& expr) {
    std::stack<int> stack;
    std::istringstream stream(expr);
    std::string token;

    while (stream >> token) {
        if (std::isdigit(token[0])) {
            int num;
            std::istringstream(token) >> num;
            stack.push(num);
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.size() < 2) {
                std::cerr << "Error: insufficient values in expression." << std::endl;
                return -1;
            }

            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            int result;

            switch (token[0]) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    if (b == 0) {
                        std::cerr << "Error: division by zero." << std::endl;
                        return -1;
                    }
                    result = a / b;
                    break;
                default:
                    std::cerr << "Error: invalid operator." << std::endl;
                    return -1;
            }

            stack.push(result);
        } else {
            std::cerr << "Error" << std::endl;
            return -1;
        }
    }

    if (stack.size() != 1) {
        std::cerr << "Error: too many values in expression." << std::endl;
        return -1;
    }

    return stack.top();
}
