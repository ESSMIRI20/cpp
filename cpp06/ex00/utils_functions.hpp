#ifndef FUNCTION_UTILS_HPP
#define FUNCTION_UTILS_HPP

#include <string>

void impossible_FloatDouble(bool floatImpossible, bool doubleImpossible, float floatVal, double doubleVal);
void impossible_ChatInt(bool charImpossible, char charVal, bool intImpossible, int intVal);

void is_FloatFunc(std::string &str, float &floatVal, bool &charImpossible, bool &intImpossible, char &charVal, int &intVal, double &doubleVal);
void is_DoubleFunc(std::string &str, float &floatVal, bool &charImpossible, bool &intImpossible, char &charVal, int &intVal, double &doubleVal);
void is_PseudoLiteralFunc(bool &charImpossible, bool &intImpossible, std::string &str, float &floatVal, double &doubleVal);

#endif