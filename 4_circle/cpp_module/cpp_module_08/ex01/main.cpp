#include "span.hpp"

int main(void)
{
	{
		std::cout << "******* Basic test *******" << std::endl;
		Span sp = Span(5);

		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		Span sp = Span(5);

		std::cout << "****** empty vector ******" << std::endl;
		try{
			sp.shortestSpan();
		}
		catch (std::exception &e){
			std::cerr << e.what() << std::endl;
		}
		try{
			sp.longestSpan();
		}
		catch (std::exception &e){
			std::cerr << e.what() << std::endl;
		}

		sp.addNumber(1);
		std::cout << "****** 1 element vector ******" << std::endl;
		try{
			sp.shortestSpan();
		}
		catch (std::exception &e){
			std::cerr << e.what() << std::endl;
		}
		try{
			sp.longestSpan();
		}
		catch (std::exception &e){
			std::cerr << e.what() << std::endl;
		}

		std::cout << "****** Full excpetion ******" << std::endl;
		try
		{
			sp.addNumber(2);
			sp.addNumber(3);
			sp.addNumber(4);
			sp.addNumber(5);
			sp.addNumber(6);
		}
		catch (std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "******* Iterator test ******* " << std::endl;

		Span sp(10000);

		std::vector<int> vec;
		for (int i = 0; i < 10000; i++){
			vec.push_back(i * 3);
		}
		sp.addNumber(vec.begin(), vec.end());

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	return (0);
}