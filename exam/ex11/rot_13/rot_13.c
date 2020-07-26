/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 10:26:44 by hopark            #+#    #+#             */
/*   Updated: 2020/07/23 20:25:53 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int ac, char *av[])
{
	int index;
	char temp;

	if (ac == 2)
	{
		while (av[1][index])
		{
			if (av[1][index] >= 'a' && av[1][index] <= 'z')
			{
				if((av[1][index] - 'a') < 13)
					temp = av[1][index] + 13;
				else
					temp = av[1][index] - 13;
				write(1, &temp, 1);
			}
			else if (av[1][index] >= 'A' && av[1][index] <= 'Z')
			{
				if((av[1][index] - 'A') < 13)
					temp = av[1][index] + 13;
				else
					temp = av[1][index] - 13;
				write(1, &temp, 1);
			}
			else
				write(1, &av[1][index], 1);
			index++;
		}

	}
}
