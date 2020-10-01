/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:21:06 by hopark            #+#    #+#             */
/*   Updated: 2020/10/01 13:43:05 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		len;
	size_t		i;
	char		*result;

	if (s == 0 || f == 0)
		return (0);
	len = ft_strlen(s);
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (s[i])
	{
		result[i] = f((unsigned int)i, s[i]);
		i++;
	}
	result[i] = 0;
	return (result);
}
