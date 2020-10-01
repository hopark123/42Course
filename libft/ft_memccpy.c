/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 12:24:59 by hopark            #+#    #+#             */
/*   Updated: 2020/10/01 17:50:59 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	while (n-- > 0)
	{
		if (*ptr2 == (unsigned char)c)
		{
			*(ptr1++) = *(ptr2++);
			return (ptr1);
		}
	}
	return (0);
}
