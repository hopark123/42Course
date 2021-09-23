#include <identify.hpp>

int main(void){
	for (int i = 0; i < 10; ++i)
	{
		Base *p = generate();
		std::cout << "*p : ";
		identify(p);
		std::cout << "&p : ";
		identify(*p);
		std::cout << "-------------" << std::endl;
	}
	return 0;
}