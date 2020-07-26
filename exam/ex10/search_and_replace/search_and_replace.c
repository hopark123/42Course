/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 10:26:44 by hopark            #+#    #+#             */
/*   Updated: 2020/07/23 19:18:54 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}
int		main(int ac, char *av[])
{
	int index;

	index = 0;
	if (ac == 4 && ft_strlen(av[2]) *ft_strlen(av[3]) == 1)
	{
		while (av[1][index])
		{
			if (av[1][index] == av[2][0])
				write(1, &av[3][0], 1);
			else
				write(1, &av[1][index], 1);
			index++;
		}
	}
	write(1, "\n", 1);
}
