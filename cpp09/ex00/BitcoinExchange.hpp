#pragma once

#include <iostream>
#include <map>
#include <string>

class BitcoinExchange
{
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &b);
    BitcoinExchange &operator=(const BitcoinExchange &b);
    ~BitcoinExchange();

    bool loadDatabase(const char* databasePath);
    bool processInputFile(const char* inputPath) const;

private:
    std::map<std::string, double> p;

    static void trim(std::string& str);
    static bool isValidDate(const std::string& date);
    static bool parseDatabaseLine(const std::string& line, std::string& date, double& price);
    static bool parseInputLine(const std::string& line, std::string& date, double& amount);
    static bool parseValue(const std::string& token, double& value);
    static bool isPositiveNumber(const std::string& token);
};
