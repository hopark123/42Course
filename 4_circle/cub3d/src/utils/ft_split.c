/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 21:34:11 by hopark            #+#    #+#             */
/*   Updated: 2021/02/26 15:34:04 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "utils.h"

static int			ft_count(char const *s, char c)
{
	int			i;
	int			cnt;

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

static int			ft_wordlen(char const *s, char c)
{
	int			i;
	int			len;

	i = 0;
	len = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static char			*ft_strndup(const char *s, int n)
{
	int			i;
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

char				**ft_split(char const *s, char c)
{
	int			i;
	int			len;
	int			cnt;
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
			ft_free2(result, i);
			return (0);
		}
		s += len;
		i++;
	}
	result[cnt] = 0;
	return (result);
}
