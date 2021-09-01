#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
class Fixed
{
	public :
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &other);
		~Fixed(void);

		Fixed &operator=(const Fixed &other);

		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		Fixed &operator++(void);
		Fixed &operator--(void);
		const Fixed operator++(int);
		const Fixed operator--(int);

		int	getRawBits(void) const;
		void	setRawBits(const int raw);
		float	toFloat( void ) const;
		int	toInt( void ) const; 

		static	Fixed &min(Fixed &a, Fixed &b);
		static	Fixed &max(Fixed &a, Fixed &b);
		static	const Fixed &min(const Fixed &a, const Fixed &b);
		static	const Fixed &max(const Fixed &a, const Fixed &b);


	private :
		int	value;
		static const int	fractional_bits = 8;
};

std::ostream &operator<<(std::ostream &ost, const Fixed &Value);

#endif