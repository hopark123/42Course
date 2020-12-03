/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:30:41 by hopark            #+#    #+#             */
/*   Updated: 2020/11/27 03:50:36 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_uitoa(unsigned long long n)
{
	int			len;
	int			i;
	char		*result;

	len = ft_uint_len(n);
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	result[len] = 0;
	i = 0;
	while (i < len)
	{
		result[len - i - 1] = n % 10 + '0';
		n /= 10;
		i++;
	}
	return (result);
}
