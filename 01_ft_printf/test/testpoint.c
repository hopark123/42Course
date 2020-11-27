#include <stdio.h>
# include <limits.h>

int main()
{
	char *format = "%30.6x\n";
	unsigned long c = 29;

	// printf("ft : %d\n" , ft_printf(format,c));
	printf("\n");
	printf("pf : %d\n",	printf(format,c));
}
