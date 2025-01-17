/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:01:10 by migupere          #+#    #+#             */
/*   Updated: 2025/01/17 16:36:52 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Prevent instantiation
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

void ScalarConverter::convert(const std::string& literal) {
    // Handle special cases first
    if (literal == "nan" || literal == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    
    if (literal == "+inf" || literal == "+inff" || 
        literal == "-inf" || literal == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << (literal[0] == '-' ? "-" : "+") << "inff" << std::endl;
        std::cout << "double: " << (literal[0] == '-' ? "-" : "+") << "inf" << std::endl;
        return;
    }

    // Check for char literal (single character in quotes)
   if (isChar(literal) || (literal.length() == 1 && !std::isdigit(literal[0]))) {
        char value = isChar(literal) ? literal[1] : literal[0];
        convertFromChar(value);
        return;
   }

    // Try to convert to different types
    try {
        if (isInt(literal)) {
            int value = std::atoi(literal.c_str());
            convertFromInt(value);
        }
        else if (isFloat(literal)) {
            float value = static_cast<float>(std::atof(literal.c_str()));
            convertFromFloat(value);
        }
        else if (isDouble(literal)) {
            double value = std::atof(literal.c_str());
            convertFromDouble(value);
        }
        else {
            std::cout << "Error: Invalid input format" << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cout << "Error: Invalid input" << std::endl;
    }
}

bool ScalarConverter::isChar(const std::string& literal) {
    return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

bool ScalarConverter::isInt(const std::string& literal) {
    if (literal.empty())
        return false;
        
    size_t i = 0;
    if (literal[0] == '-' || literal[0] == '+')
        i++;
        
    for (; i < literal.length(); i++) {
        if (!std::isdigit(literal[i]))
            return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string& literal) {
    if (literal.empty())
        return false;
        
    // Check if it ends with 'f'
    if (literal[literal.length() - 1] != 'f')
        return false;
        
    // Remove the 'f' and check if it's a valid floating point number
    std::string temp = literal.substr(0, literal.length() - 1);
    
    size_t i = 0;
    bool hasDecimal = false;
    
    if (temp[0] == '-' || temp[0] == '+')
        i++;
        
    for (; i < temp.length(); i++) {
        if (temp[i] == '.') {
            if (hasDecimal)
                return false;
            hasDecimal = true;
        }
        else if (!std::isdigit(temp[i]))
            return false;
    }
    return true;
}

bool ScalarConverter::isDouble(const std::string& literal) {
    if (literal.empty())
        return false;
        
    size_t i = 0;
    bool hasDecimal = false;
    
    if (literal[0] == '-' || literal[0] == '+')
        i++;
        
    for (; i < literal.length(); i++) {
        if (literal[i] == '.') {
            if (hasDecimal)
                return false;
            hasDecimal = true;
        }
        else if (!std::isdigit(literal[i]))
            return false;
    }
    return hasDecimal;
}

void ScalarConverter::convertFromChar(char value) {
    double dValue = static_cast<double>(value);
    printChar(dValue);
    printInt(dValue);
    printFloat(dValue);
    printDouble(dValue);
}

void ScalarConverter::convertFromInt(int value) {
    double dValue = static_cast<double>(value);
    printChar(dValue);
    printInt(dValue);
    printFloat(dValue);
    printDouble(dValue);
}

void ScalarConverter::convertFromFloat(float value) {
    double dValue = static_cast<double>(value);
    printChar(dValue);
    printInt(dValue);
    printFloat(dValue);
    printDouble(dValue);
}

void ScalarConverter::convertFromDouble(double value) {
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

void ScalarConverter::printChar(double value) {
    if (std::isnan(value) || std::isinf(value) || 
        value < 0 || value > 127) {
        std::cout << "char: impossible" << std::endl;
    }
    else if (value < 32 || value > 126) {
        std::cout << "char: Non displayable" << std::endl;
    }
    else {
        std::cout << "char: " << static_cast<char>(value) << std::endl;
    }
}

void ScalarConverter::printInt(double value) {
    if (std::isnan(value) || std::isinf(value) || 
        value > std::numeric_limits<int>::max() || 
        value < std::numeric_limits<int>::min()) {
        std::cout << "int: impossible" << std::endl;
    }
    else {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }
}

void ScalarConverter::printFloat(double value) {
    if (std::isnan(value)) {
        std::cout << "float: nanf" << std::endl;
    }
    else if (std::isinf(value)) {
        std::cout << "float: " << (value < 0 ? "-" : "+") << "inff" << std::endl;
    }
    else {
        std::cout << "float: " << static_cast<float>(value);
        // Check if the value is a whole number
        if (value == static_cast<int>(value))
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(double value) {
     std::cout << "double: " << value;
    // Check if the value is a whole number
    if (value == static_cast<int>(value))
        std::cout << ".0";
    std::cout << std::endl;
}
