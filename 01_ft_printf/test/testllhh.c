#include <stdio.h>
# include <limits.h>

int main()
{
	char *format = "%ld\n";
	long long int a = LLONG_MAX;

	a+= 3;
	printf("%lld\n", a);
	a-= 3;

	printf(format, LONG_MAX);
	printf("%ld\n", LONG_MAX);
	printf("%lld\n", a);
}
