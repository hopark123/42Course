/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 21:34:11 by hopark            #+#    #+#             */
/*   Updated: 2021/05/11 17:48:45 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_count(char const *s, char c)
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

static int	ft_wordlen(char const *s, char c)
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

char	**ft_split(char const *s, char c)
{
	int			i;
	int			len;
	int			cnt;
	char		**result;

	i = -1;
	cnt = ft_count(s, c);
	if (!s)
		return (0);
	if (!ft_malloc(&result, sizeof(char *) * (cnt + 1)))
		return (0);
	while (++i < cnt)
	{
		while (*s && *s == c)
			s++;
		len = ft_wordlen(s, c);
		result[i] = ft_strndup(s, len);
		if (!(result[i]))
			ft_free(result);
		s += len;
	}
	result[cnt] = 0;
	return (result);
}
