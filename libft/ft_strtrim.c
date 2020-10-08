/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:26:36 by hopark            #+#    #+#             */
/*   Updated: 2020/10/08 19:41:25 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_front(char const *s1, char const *set, size_t len)
{
	size_t i;

	i = 0;
	while (i < len && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

static size_t		ft_back(char const *s1, char const *set, size_t len)
{
	size_t i;

	i = len - 1;
	while (i > 0 && ft_strchr(set, s1[i]))
		i--;
	return (i);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	size_t		len;
	size_t		front;
	size_t		back;
	char		*result;

	len = ft_strlen(s1);
	front = ft_front(s1, set, len);
	back = ft_back(s1, set, len);
	if (front >= back)
		return (ft_calloc(1, sizeof(char)));
	if (!(result = (char *)malloc(sizeof(char) * (back - front + 2))))
		return (0);
	ft_memcpy(result, s1 + front, back - front + 1);
	result[back - front + 1] = '\0';
	return (result);
}
