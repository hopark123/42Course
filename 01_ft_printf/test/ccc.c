#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// void	ft(char **c, char **s)
// {

// 	c = (char **)malloc(sizeof(char *)*3);
// 	*c = (char *)malloc(sizeof(char) * 3);
// 	*c[0] = 'a';
// 	*c[1] = 'a';

// 	*s = *c + 1;
// 	// free(c);
// }

// int main()
// {
// 	char **c;
// 	char **s;
// 	s = (char **)malloc(sizeof(char *)*3);

// 	ft(c,s);

// 	printf("s%s\n", *s);
// 	free(s);
// 	printf("c%c\n", *c[0]);

// }
#include <string.h>

char * fd(char *c)
{
	c = (char *)malloc(sizeof(char)*4);
	c[0]= 1;
	c[1]=2;

	return (c);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *ptr1;
	unsigned char *ptr2;

	if (!dest && !src)
		return (0);
	ptr1 = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	while (n-- > 0)
	{
		*(ptr1++) = *(ptr2++);
	}
	return (dest);
}


int main()
{
	char s[5];
	char *c;
	c = malloc (4);
	while(1);
}
