/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 17:35:48 by hopark            #+#    #+#             */
/*   Updated: 2020/10/09 01:07:05 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_count(char const *s, char c)
{
	size_t		i;
	size_t		cnt;

	i = 0;
	cnt = 0;
	if (s == 0)
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		cnt++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (cnt);
}

static size_t		ft_wordlen(char const *s, char c)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static char			*ft_strndup(const char *s, size_t n)
{
	size_t		i;
	char		*result;

	if (!(result = (char *)malloc(sizeof(char) * (n + 1))))
		return (0);
	i = 0;
	while (i < n)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

static void			ft_free(char **s, int i)
{
	while (i--)
		free(s[i]);
	free(s);
}

char				**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		len;
	size_t		cnt;
	char		**result;

	cnt = ft_count(s, c);
	if (!(result = (char **)malloc(sizeof(char *) * (cnt + 1))) || s == 0)
		return (0);
	i = 0;
	while (i < cnt)
	{
		while (*s && *s == c)
			s++;
		len = ft_wordlen(s, c);
		if (!(result[i] = ft_strndup(s, len)))
		{
			ft_free(result, i);
			return (0);
		}
		s += len;
		i++;
	}
	result[cnt] = 0;
	return (result);
}
