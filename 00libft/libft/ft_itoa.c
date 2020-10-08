/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:23:07 by hopark            #+#    #+#             */
/*   Updated: 2020/10/01 13:22:04 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		get_len(int n)
{
	size_t		len;
	long long	n2;

	len = 0;
	n2 = (long long)n;
	if (n2 < 0)
	{
		len++;
		n2 *= -1;
	}
	while (n2 >= 10)
	{
		len++;
		n2 /= 10;
	}
	return (++len);
}

char				*ft_itoa(int n)
{
	size_t		len;
	size_t		i;
	long long	n2;
	char		*result;

	len = get_len(n);
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
