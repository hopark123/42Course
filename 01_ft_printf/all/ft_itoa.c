/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:30:41 by hopark            #+#    #+#             */
/*   Updated: 2020/11/26 18:28:50 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	int			len;
	int			i;
	long long	n2;
	char		*result;

	len = ft_int_len(n);
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	result[len] = 0;
	i = 0;
	n2 = n < 0 ? (long long)n * -1 : (long long)n;
	while (i < len)
	{
		result[len - i - 1] = n2 % 10 + '0';
		n2 /= 10;
		i++;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}
