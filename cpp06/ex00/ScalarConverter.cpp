#include "ScalarConverter.hpp"
#include "utils_functions.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	(void)src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void)rhs;
	return *this;
}

ScalarConverter::~ScalarConverter(void) {}

bool ScalarConverter::isPseudoLiteral(const std::string &str)
{
	return str == "nanf" || str == "nan" || str == "+inff" || str == "-inff" || 
	       str == "+inf" || str == "-inf";
}

bool ScalarConverter::isChar(const std::string &str)
{
	 return (str.length() == 1 && !isdigit(str[0]));
}

bool ScalarConverter::isInt(const std::string &str)
{
	if (str.empty())
		return false;
	
	size_t start = 0;
	if (str[0] == '+' || str[0] == '-')
		start = 1;
	
	if (start >= str.length())
		return false;
	
	for (size_t i = start; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string &str)
{
	if (str.empty() || str[str.length() - 1] != 'f')
		return false;
	
	std::string temp = str.substr(0, str.length() - 1);
	if (temp.empty())
		return false;
	
	if (isPseudoLiteral(str))
		return true;
	
	size_t start = 0;
	if (temp[0] == '+' || temp[0] == '-')
		start = 1;
	
	if (start >= temp.length())
		return false;
	
	bool pointFound = false;
	for (size_t i = start; i < temp.length(); i++)
	{
		if (temp[i] == '.')
		{
			if (pointFound)
				return false;
			pointFound = true;
		}
		else if (!isdigit(temp[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isDouble(const std::string &str)
{
	if (str.empty())
		return false;
#include "ScalarConverter.hpp"
	
	if (isPseudoLiteral(str))
		return true;
	
	size_t start = 0;
	if (str[0] == '+' || str[0] == '-')
		start = 1;
	
	if (start >= str.length())
		return false;
	
	bool pointFound = false;
	for (size_t i = start; i < str.length(); i++)
	{
		if (str[i] == '.')
		{
			if (pointFound)
				return false;
			pointFound = true;
		}
		else if (!isdigit(str[i]))
			return false;
	}
	return pointFound;
}

void ScalarConverter::convert(std::string str)
{
	char charVal;
	int intVal;
	float floatVal;
	double doubleVal;

	bool charImpossible = false;
	bool intImpossible = false;
	bool floatImpossible = false;
	bool doubleImpossible = false;

	if (isChar(str))
	{
		charVal = str[0];
		intVal = static_cast<int>(charVal);
		floatVal = static_cast<float>(charVal);
		doubleVal = static_cast<double>(charVal);
	}
	else if (isPseudoLiteral(str))
		is_PseudoLiteralFunc(charImpossible, intImpossible, str, floatVal, doubleVal);
	else if (isInt(str))
	{
		std::istringstream iss(str);
		iss >> intVal;
		
		charVal = static_cast<char>(intVal);
		floatVal = static_cast<float>(intVal);
		doubleVal = static_cast<double>(intVal);
	}
	else if (isFloat(str))
		is_FloatFunc(str, floatVal, charImpossible, intImpossible, charVal, intVal, doubleVal);
	else if (isDouble(str))
		is_DoubleFunc(str, floatVal, charImpossible, intImpossible, charVal, intVal, doubleVal);
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	impossible_ChatInt(charImpossible, charVal, intImpossible, intVal);	
	impossible_FloatDouble(doubleImpossible, floatImpossible, doubleVal, floatVal);
}
