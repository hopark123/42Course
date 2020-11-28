#include <stdio.h>

int main()
{
	char *format ="@%+06.4%@\n";
	printf("return : %d\n", printf(format,0));
}
