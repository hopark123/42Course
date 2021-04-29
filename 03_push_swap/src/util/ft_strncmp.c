/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:58:35 by hopark            #+#    #+#             */
/*   Updated: 2021/04/28 19:47:40 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int				ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	if (ft_strlen(s1) != n || ft_strlen(s2) !=n)
		return (0);
	while (i + 1 < n)
	{
		if (c1[i] != c2[i])
			break ;
		if (c1[i] * c2[i] == 0)
			break ;
		i++;
	}
	return (c1[i] - c2[i]);
}
