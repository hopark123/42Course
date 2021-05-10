#include <unsitd.h>

int			main(int ac, char *av)
{
	int i;
	int j;
	int temp;
	int flag;

	if (ac != 3)
		return (0);
	i = 0;
	while (av[1][i])
	{
		temp = i;
		while (av[1][--temp] && temp >= 0)
		{
			if (av[1][temp] == av[1][i])
				break ;
		}
		if (temp < 0)
			write(1, &av[1][i], 1);
		i++;
	}
	i = 0;
	while (av[2][i])
	{
		j = 0;
		flag = 0;
		while (av[1][j])
		{
			if (av[1][j] == av[2][i])
			{
				flag = 1;
				break;
			}
			j++;
		}
		temp = i;
		if (flag == 0)
		{
			while (av[2][--temp] && temp >= 0)
			{
				if (av[2][i] == av[2][temp])
					break ;
			}
			if (temp < 0)
				write(1, &av[2][i], 1);
		}
	}
}