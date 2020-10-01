/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:11:53 by hopark            #+#    #+#             */
/*   Updated: 2020/10/01 17:03:21 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *ptr1;
	unsigned char *ptr2;

	ptr1 = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	if (dest <= src)
	{
		while (n-- >= 0)
			*(ptr1++) = *(ptr2++);
	}
	else
	{
		ptr1 += n;
		ptr2 += n;
		while (n-- >= 0)
			*(ptr1--) = *(ptr2--);
	}
	return (dest);
}
