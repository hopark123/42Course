/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:22:29 by hopark            #+#    #+#             */
/*   Updated: 2021/04/29 15:50:24 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void			ft_free(void *memory)
{
	if (memory)
		free(memory);
}

void			ft_free2(char **s, int i)
{
	while (i--)
	{
		if (s[i])
			ft_free(s[i]);
	}
	ft_free(s);
}