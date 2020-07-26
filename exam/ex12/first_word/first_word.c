/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 10:26:44 by hopark            #+#    #+#             */
/*   Updated: 2020/07/23 22:01:01 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int ac, char *av[])
{
	int index;

	index = 0;
	if (ac == 2)
	{
		while (av[1][index] == ' ')
			index++;
		while (av[1][index])
		{
			write(1, &av[1][index], 1);
			if (av[1][index] == ' ')
				break;
			index++;
		}
	}
	write(1, "\n", 1);
}
