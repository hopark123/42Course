/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 10:26:44 by hopark            #+#    #+#             */
/*   Updated: 2020/07/23 19:02:05 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


int		main(int ac, char *av[])
{
	int		index;
	int		cnt;

	index = 0;
	if (ac == 2)
	{
		while (av[1][index])
		{
			cnt = 1;
			if (av[1][index] >= 'a' && av[1][index] <= 'z')
				cnt = av[1][index] - 'a' + 1;
			else if (av[1][index] >= 'A' && av[1][index] <= 'Z')
				cnt = av[1][index] - 'A' + 1;

			while (cnt--)
				write(1, &av[1][index], 1);
			index++;
		}
	}
	write(1, "\n", 1);
}
