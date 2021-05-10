/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:00:01 by hopark            #+#    #+#             */
/*   Updated: 2021/03/08 15:05:56 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr1;
	unsigned char		*ptr2;
	size_t				i;

	ptr1 = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	i = 0;
	if (dest == src || n == 0)
		return (dest);
	if (dest < src)
		while (i < n)
		{
			ptr1[i] = ptr2[i];
			i++;
		}
	else
		while (i < n)
		{
			ptr1[n - i - 1] = ptr2[n - i - 1];
			i++;
		}
	return (dest);
}
