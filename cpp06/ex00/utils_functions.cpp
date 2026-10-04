#include "ScalarConverter.hpp"

void impossible_FloatDouble(bool floatImpossible, bool doubleImpossible, float floatVal, double doubleVal)
{
    if (floatImpossible)
		std::cout << "float: impossible" << std::endl;
	else
	{
		if (std::isnan(floatVal))
			std::cout << "float: nanf" << std::endl;
		else if (std::isinf(floatVal))
		{
			if (floatVal > 0)
				std::cout << "float: +inff" << std::endl;
			else
				std::cout << "float: -inff" << std::endl;
		}
		else
			std::cout << "float: " << std::fixed << std::setprecision(1) << floatVal << "f" << std::endl;
	}
	
	if (doubleImpossible)
		std::cout << "double: impossible" << std::endl;
	else
	{
		if (std::isnan(doubleVal))
			std::cout << "double: nan" << std::endl;
		else if (std::isinf(doubleVal))
		{
			if (doubleVal > 0)
				std::cout << "double: +inf" << std::endl;
			else
				std::cout << "double: -inf" << std::endl;
		}
		else
			std::cout << "double: " << std::fixed << std::setprecision(1) << doubleVal << std::endl;
	}
}

void impossible_ChatInt(bool charImpossible, char charVal, bool intImpossible, int intVal)
{
    if (charImpossible)
		std::cout << "char: impossible" << std::endl;
	else if (charVal < 32 || charVal > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << charVal << "'" << std::endl;
	
	if (intImpossible)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << intVal << std::endl;
}

void is_FloatFunc(std::string &str, float &floatVal, bool &charImpossible, bool &intImpossible, char &charVal, int &intVal, double &doubleVal)
{
    std::istringstream iss(str.substr(0, str.length() - 1));
		iss >> floatVal;
		
		if (std::isnan(floatVal) || std::isinf(floatVal))
		{
			charImpossible = true;
			intImpossible = true;
		}
		else if (floatVal > 127 || floatVal < -128)
			charImpossible = true;
		else if (floatVal < std::numeric_limits<int>::min() || floatVal > std::numeric_limits<int>::max())
			intImpossible = true;
		else
		{
			charVal = static_cast<char>(floatVal);
			intVal = static_cast<int>(floatVal);
		}
		doubleVal = static_cast<double>(floatVal);
}

void is_DoubleFunc(std::string &str, float &floatVal, bool &charImpossible, bool &intImpossible, char &charVal, int &intVal, double &doubleVal)
{
    std::istringstream iss(str);
		iss >> doubleVal;
		
		if (std::isnan(doubleVal) || std::isinf(doubleVal))
		{
			charImpossible = true;
			intImpossible = true;
		}
		else if (doubleVal > 127 || doubleVal < -128)
			charImpossible = true;
		else if (doubleVal < std::numeric_limits<int>::min() || doubleVal > std::numeric_limits<int>::max())
			intImpossible = true;
		else
		{
			charVal = static_cast<char>(doubleVal);
			intVal = static_cast<int>(doubleVal);
		}
		floatVal = static_cast<float>(doubleVal);
}

void is_PseudoLiteralFunc(bool &charImpossible, bool &intImpossible, std::string &str, float &floatVal, double &doubleVal)
{
    charImpossible = true;
		intImpossible = true;
		
		if (str == "nanf" || str == "nan")
		{
			floatVal = std::numeric_limits<float>::quiet_NaN();
			doubleVal = std::numeric_limits<double>::quiet_NaN();
		}
		else if (str == "+inff" || str == "+inf")
		{
			floatVal = std::numeric_limits<float>::infinity();
			doubleVal = std::numeric_limits<double>::infinity();
		}
		else
		{
			floatVal = -std::numeric_limits<float>::infinity();
			doubleVal = -std::numeric_limits<double>::infinity();
		}
}
