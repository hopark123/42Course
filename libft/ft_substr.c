/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:28:26 by hopark            #+#    #+#             */
/*   Updated: 2020/10/01 17:03:54 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*result;

	if (ft_strlen(s) <= len)
		return (ft_calloc(1, sizeof(char)));
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_memcpy(result, s + start, len);
	result[len] = '\0';
	return (result);
}
