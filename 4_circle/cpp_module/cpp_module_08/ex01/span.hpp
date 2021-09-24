#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iterator>
# include <iostream>

class Span {
private :
	unsigned int	_size;
	std::vector<int> _value;
	Span();
public :
	Span(unsigned int	N);
	Span(const Span &other);
	Span &operator=(const Span &otehr);
	~Span();
	int	&operator[](int i);

	void	addNumber(int n);
	void	addNumber(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end);

	unsigned int	longestSpan() const;
	unsigned int	shortestSpan() const;

	class FullSpanException : public std::exception {
	public :
		const char *what() const throw(){
			return ("Span is full");
		}
	};

	class OutofRangeException : public std::exception {
	public :
		const char *what() const throw(){
			return ("Out of Range");
		}
	};
	
	class TooShortSpanException : public std::exception {
	public :
		const	char *what() const throw(){
			return ("Span is too short");
		}
	};
};

#endif
