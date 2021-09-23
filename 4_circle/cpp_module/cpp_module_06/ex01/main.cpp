#include "seriasization.hpp"

int main(void){
	Data	*data = new Data;
	data->str = "CPP";
	data->num = 6;

	
	uintptr_t mid = serialize(data);
	Data *out = deserialize(mid);
	std::cout << "str : " << out->str << std::endl;
	std::cout << "num : " << out->num << std::endl;
	delete data;
}