#include <unistd.h>

int main(int ac, char *av[])
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	if (ac != 3)
		return (0);
	while(av[1][i])
	{
		j = 0;
		while (av[2][j])
		{
			if (av[1][i] == av[2][j])
			{
				temp = i;
				while (av[1][--temp] && temp >= 0)
				{
					if	(av[1][i] == av[1][temp])
						break;
				}
				if (temp < 0)
					write(1, &av[1][i], 1);
				break;
			}
			j++;
		}
		i++;
	}
}