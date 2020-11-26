/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:22:52 by hopark            #+#    #+#             */
/*   Updated: 2020/11/26 18:24:32 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_bzero_c(void *s, int n, char c)
{
	unsigned char *ptr;

	ptr = (unsigned char*)s;
	while (n-- > 1)
	{
		*(ptr++) = c;
	}
	*ptr = 0;
}
