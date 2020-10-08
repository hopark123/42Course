/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:11:52 by hopark            #+#    #+#             */
/*   Updated: 2020/10/08 19:21:25 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *ptr1;
	unsigned char *ptr2;

	if (!dest && !src)
		return (0);
	ptr1 = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	while (n-- > 0)
	{
		*(ptr1++) = *(ptr2++);
	}
	return (dest);
}
