/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:24:42 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/20 14:32:24 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(const char *s)
{
	int				i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int				i;
	unsigned char	*c1;
	unsigned char	*c2;

	if (n == 0 || !s1 || !s2)
		return (0);
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	if (ft_strlen(s1) != n)
		return (0);
	while (i < n)
	{
		if (c1[i] != c2[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strndup(const char *s, int len)
{
	char		*temp;

	if (!(ft_malloc(&temp, sizeof(char) * (len + 1))))
		return (0);
	ft_memcpy(temp, s, len);
	temp[len] = 0;
	return (temp);
}

void	*ft_memcpy(void *dst, const void *src, int n)
{
	unsigned char		*s1;
	const unsigned char	*s2;

	if (!dst && !src)
		return (0);
	s1 = dst;
	s2 = src;
	while (n-- > 0)
	{
		*s1++ = *s2++;
	}
	return (dst);
}

char	*ft_strchr(const char *s, char c)
{
	while (*s != c)
	{
		if (*s == 0)
			return (0);
		s++;
	}
	return ((char *)s);
}
