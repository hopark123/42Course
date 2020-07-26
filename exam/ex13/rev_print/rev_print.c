	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 10:26:44 by hopark            #+#    #+#             */
/*   Updated: 2020/07/23 18:49:35 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		main(int ac, char *av[])
{
	int len;
	int index;

	if (ac == 2)
	{
		len = ft_strlen(av[1]);
		index = len;
		while (index >= 0)
		{
			write(1, &av[1][index], 1);
			index--;
		}
	}
	write(1, "\n", 1);
}
