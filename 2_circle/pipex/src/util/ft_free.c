/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:34:40 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/14 19:03:00 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_free(void *memory)
{
	if (memory)
	{
		free(memory);
		memory = 0;
	}
}

void	ft_free2(char **s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i])
			ft_free(s[i]);
		i++;
	}
	ft_free(s);
}
