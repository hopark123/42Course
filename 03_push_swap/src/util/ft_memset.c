/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:30:09 by hopark            #+#    #+#             */
/*   Updated: 2021/05/07 16:32:01 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "head.h"

void	*ft_memset(void *s, int c, int n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n-- > 0)
	{
		*(ptr++) = (unsigned char)c;
	}
	return (s);
}
