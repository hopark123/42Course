/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:25:47 by hopark            #+#    #+#             */
/*   Updated: 2021/02/26 14:49:29 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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