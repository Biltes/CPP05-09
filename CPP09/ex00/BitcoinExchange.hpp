#pragma once

// #include <algorithm>
// #include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _priceData;

		void loadDatabase(const std::string &filename);
		float getExchangeRate(const std::string &date) const;
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &other);
		BitcoinExchange &operator=(BitcoinExchange const &other);
		~BitcoinExchange();

		void processInputFile(const std::string &filename) const;

		bool isValidDate(const std::string &date) const;
		bool isLeapYear(int year) const;
};