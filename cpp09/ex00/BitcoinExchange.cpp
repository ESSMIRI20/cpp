#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cctype>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& b) : p(b.p)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& b)
{
    if (this != &b)
        p = b.p;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::loadDatabase(const char* databasePath)
{
    std::ifstream file(databasePath);
    if (!file.is_open())
        return false;

    std::string line;
    bool firstLine = true;
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        std::string date;
        double price;
        if (firstLine)
        {
            firstLine = false;
            if (line.find("date") != std::string::npos && line.find("price") != std::string::npos)
                continue;
        }
        if (!parseDatabaseLine(line, date, price))
            continue;
        p[date] = price;
    }
    return !p.empty();
}

bool BitcoinExchange::processInputFile(const char* inputPath) const
{
    std::ifstream file(inputPath);
    if (!file.is_open())
        return false;

    std::string line;
    bool firstLine = true;
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        if (firstLine)
        {
            firstLine = false;
            std::string header = line;
            trim(header);
            if (header == "date | value" || header == "date|value")
                continue;
        }

        std::string date;
        double amount;
        if (!parseInputLine(line, date, amount))
            continue;

        if (p.empty())
            continue;

        std::map<std::string, double>::const_iterator it = p.lower_bound(date);
        if (it == p.begin() && it->first != date)
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (it == p.end() || it->first != date)
            --it;

        std::cout << date << " => " << amount << " = " << (amount * it->second) << std::endl;
    }
    return true;
}

void BitcoinExchange::trim(std::string& str)
{
    size_t start = 0;
    while (start < str.size() && std::isspace(static_cast<unsigned char>(str[start])))
        ++start;
    size_t end = str.size();
    while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1])))
        --end;
    str = str.substr(start, end - start);
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    for (size_t i = 0; i < date.size(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }

    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1)
        return false;

    int daysInMonth = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11)
        daysInMonth = 30;
    else if (month == 2)
        daysInMonth = 28;

    return day <= daysInMonth;
}

bool BitcoinExchange::parseDatabaseLine(const std::string& line, std::string& date, double& price)
{
    size_t commaPos = line.find(',');
    if (commaPos == std::string::npos)
        return false;
    date = line.substr(0, commaPos);
    std::string value = line.substr(commaPos + 1);
    trim(date);
    trim(value);
    if (!isValidDate(date))
        return false;
    if (!parseValue(value, price))
        return false;
    return true;
}

bool BitcoinExchange::isPositiveNumber(const std::string& token)
{
    if (token.empty())
        return false;
    bool hasDigit = false;
    int dotCount = 0;
    for (size_t i = 0; i < token.size(); ++i)
    {
        char c = token[i];
        if (c == '.')
        {
            ++dotCount;
            if (dotCount > 1)
                return false;
            continue;
        }
        if (!std::isdigit(static_cast<unsigned char>(c)))
            return false;
        if (std::isdigit(static_cast<unsigned char>(c)))
            hasDigit = true;
    }
    if (!hasDigit)
        return false;
    return true;
}

bool BitcoinExchange::parseValue(const std::string& token, double& value)
{
    std::string trimmed = token;
    trim(trimmed);
    if (trimmed.empty())
        return false;
    if (!isPositiveNumber(trimmed))
        return false;
    std::istringstream iss(trimmed);
    iss >> value;
    if (iss.fail() || !iss.eof())
        return false;
    return true;
}

bool BitcoinExchange::parseInputLine(const std::string& line, std::string& date, double& amount)
{
    size_t sep = line.find('|');
    if (sep == std::string::npos)
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return false;
    }
    date = line.substr(0, sep);
    std::string value = line.substr(sep + 1);
    trim(date);
    trim(value);
    if (!isValidDate(date))
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return false;
    }
    if (!isPositiveNumber(value))
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    std::istringstream iss(value);
    iss >> amount;
    if (iss.fail() || !iss.eof())
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return false;
    }
    if (amount < 0.0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (amount > 1000.0)
    {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}
