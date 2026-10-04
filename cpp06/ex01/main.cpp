#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data data;
	data.value = 42;
	data.name = 'A';
	data.score = 3.14;
	
	std::cout << "data address: " << &data << std::endl;
	std::cout << "data values: value=" << data.value << ", name=" << data.name << ", score=" << data.score << std::endl;
	
	uintptr_t serialized = Serializer::serialize(&data);
	
	Data *deserialized = Serializer::deserialize(serialized);
	std::cout << "deserialized address: " << deserialized << std::endl;
	
	if (&data == deserialized)
	{
		std::cout << "Success" << std::endl;
		std::cout << "deserialized value=" << deserialized->value << ", name=" << deserialized->name << ", score=" << deserialized->score << std::endl;
	}
	else
		std::cout << "Failure" << std::endl;

	return 0;
}
