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
	printf("%d\n", (char)280);
	printf("%lld\n", a);
}