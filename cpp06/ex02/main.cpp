#include "Base.hpp"
#include <iostream>

int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		Base *obj = generate();
		
		std::cout << "Pointer identify: ";
		identify(obj);
		
		std::cout << "Reference identify: ";
		identify(*obj);
		
		std::cout << std::endl;
		
		delete obj;
	}
	
	return 0;
}
