#include <stdio.h>

int		ft_printf(char *s, ...);

int		main()
{
	printf("#%d#", ft_printf("%1d", 23));
}
