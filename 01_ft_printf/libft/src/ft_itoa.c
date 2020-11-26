/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:30:41 by hopark            #+#    #+#             */
/*   Updated: 2020/11/27 03:38:17 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(long long n)
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
	if (n == LLONG_MIN)
	{
		free(result);
		return (ft_llmin(result));
	}
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

char			*ft_llmin(char *result)
{
	if (!(result = malloc(sizeof(char) * (20))))
		return (0);
	result[0] = '9';
	result[1] = '2';
	result[2] = '2';
	result[3] = '3';
	result[4] = '3';
	result[5] = '7';
	result[6] = '2';
	result[7] = '0';
	result[8] = '3';
	result[9] = '6';
	result[10] = '8';
	result[11] = '5';
	result[12] = '4';
	result[13] = '7';
	result[14] = '7';
	result[15] = '5';
	result[16] = '8';
	result[17] = '0';
	result[18] = '8';
	result[19] = 0;
	return (result);
}
