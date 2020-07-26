/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 10:26:44 by hopark            #+#    #+#             */
/*   Updated: 2020/07/23 19:29:43 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char *av[])
{
	int index;
	char temp;

	index = 0;
	if (ac == 2)
	{
		while (av[1][index])
		{
			if (av[1][index] >= 'a' && av[1][index] <= 'z')
			{
				temp = av[1][index] - 32;
				write(1, &temp, 1);
			}
			else if (av[1][index] >= 'A' && av[1][index] <= 'Z')
			{
				temp = av[1][index] + 32;
				write(1, &temp, 1);
			}
			else
				write(1, &av[1][index], 1);
			index++;
		}
	}
	write(1, "\n", 1);
}
