/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 10:26:44 by hopark            #+#    #+#             */
/*   Updated: 2020/07/23 23:43:49 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int ac, char *av[])
{
	int 	index;
	char 	c;
	index = 0;
	if (ac == 2)
	{
		while (av[1][index])
		{
			if ((av[1][index] >= 'a' && av[1][index] < 'z' )|| (av[1][index] >='A' && av[1][index] < 'Z'))
				c = av[1][index] + 1;
			else if (av[1][index] == 'z')
				c = 'a';
			else if (av[1][index] == 'Z')
				c = 'A';
			else
				c = av[1][index];
			write(1, &c, 1);
			index++;
		}
	}
	write(1, "\n", 1);
}
