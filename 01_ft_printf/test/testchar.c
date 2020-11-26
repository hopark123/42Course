#include <stdio.h>

int main()
{
	char *format ="@%06.2s@\n";
	printf("return : %d\n", printf(format,0));
}
