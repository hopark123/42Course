/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:07:14 by hopark            #+#    #+#             */
/*   Updated: 2020/11/10 15:11:43 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int		storejoin(char **store, char *buf, ssize_t readsize)
{
	char		*temp;

	buf[readsize] = 0;
	if (*store == NULL)
		temp = ft_strndup(buf, readsize);
	else
	{
		temp = ft_strjoin(*store, buf);
		free(*store);
	}
	*store = temp;
	if (ft_strchr(*store, '\n'))
		return (1);
	return (0);
}

static int		make_line(char **store, char **line)
{
	char		*ptr;
	char		*temp;

	if ((ptr = ft_strchr(*store, '\n')))
	{
		*line = ft_strndup(*store, ptr - *store);
		temp = ft_strndup(ptr + 1, ft_strlen(ptr + 1));
		free(*store);
		*store = temp;
		return (1);
	}
	else
	{
		*line = *store;
		*store = 0;
		return (0);
	}
}

int				get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*store[OPEN_MAX];
	ssize_t		readsize;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((readsize = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		if (storejoin(&store[fd], buf, readsize) || readsize <= 0)
			break ;
	}
	free(buf);
	if (readsize < 0)
		return (-1);
	return (make_line(&store[fd], line));
}
