/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:25:02 by hopark            #+#    #+#             */
/*   Updated: 2021/02/27 15:30:41 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_memcmp(const void *s1, const void *s2, int n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	int				i;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return ((int)(ptr1[i] - ptr2[i]));
		i++;
	}
	return (0);
}