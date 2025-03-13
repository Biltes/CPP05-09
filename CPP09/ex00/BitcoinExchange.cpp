#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        this->_priceData = other._priceData;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, priceStr;
        if (!std::getline(ss, date, ',') || !std::getline(ss, priceStr)) {
            continue;
        }
        float price = std::atof(priceStr.c_str());
        _priceData[date] = price;
    }

    file.close();
}

bool BitcoinExchange::isLeapYear(int year) const{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}


bool BitcoinExchange::isValidDate(const std::string &date) const {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    int year, month, day;
    char dash1, dash2;
    std::stringstream ss(date);
    if (!(ss >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-') {
        return false;
    }
    if (month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }

    if (month == 2) {
        if (day > 29 || (day == 29 && !isLeapYear(year))) {
            return false;
        }
    } else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    } else if (day > 31) {
        return false;
    }

    return true;
}


float BitcoinExchange::getExchangeRate(const std::string &date) const {
    std::map<std::string, float>::const_iterator it = _priceData.lower_bound(date);
    
    if (it == _priceData.end() || it->first != date) {
        if (it != _priceData.begin()) {
            --it;
        } else {
            return -1;
        }
    }

    return it->second;
}

void BitcoinExchange::processInputFile(const std::string &filename) const {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, valueStr;
        
        if (!std::getline(ss, date, ' ') || !std::getline(ss, valueStr)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        valueStr.erase(0, valueStr.find_first_not_of(" |"));
        
        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        double value;
        std::stringstream valueStream(valueStr);
        if (!(valueStream >> value) || value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
		char extra;
		if (valueStream >> extra) {
			std::cerr << "Error: bad input => " << valueStream.str() << std::endl;
			continue;
		}
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        
        float rate = getExchangeRate(date);
        if (rate == -1) {
            std::cerr << "Error: no valid exchange rate for " << date << std::endl;
            continue;
        }
        
        std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
    }

    file.close();
}