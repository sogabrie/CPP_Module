#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	for (size_t i = 0; i < 5; i++)
	{
		sp.addNumber(i);
	}
	std::cout << sp;
	// sp.addNumber(6);
	// sp.addNumber(3);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);
	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;
	return 0;
}