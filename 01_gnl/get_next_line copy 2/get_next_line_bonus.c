/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 20:59:49 by hopark            #+#    #+#             */
/*   Updated: 2020/10/10 20:53:03 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
static int			read_error(char **remain)
{
	if (*remain != NULL)
	{
		free(*remain);
		*remain = 0;
	}
	return (-1);
}

static int			read_eof(char **line, char **remain)
{
	char		*temp;

	if (remain == 0)
	{
		if (!(temp = (char *)malloc(1 * sizeof(char))))
			return (read_error(remain));
		temp[0] = 0;
		*line = temp;
	}
	else
		make_line(line, remain, 0);
	return (0);
}

static int			make_line(char **line, char**remain, char *line_ptr)
{
	char		*temp;
	size_t		remain_size;
	size_t		line_size;

	remain_size = ft_strlen(*remain);
	line_size = (line_ptr == 0) ?  remain_size : line_ptr - *remain;
	if (!(temp = (char *)malloc(sizeof(char) * (line_size + 1))))
		return (read_error(remain));
	ft_strncpy(temp, *remain, line_size);
	temp[line_size] = 0;
	*line = temp;
	if (line_ptr == 0)
	{
		free(remain);
		*remain = 0;
		return (1);
	}
	if (!(temp = (char *)malloc(sizeof(char) * (remain_size - (line_size + 1)+1))))
		return (read_error(remain));
	temp[remain_size - (line_size + 1)] = 0;
	free(*remain);
	*remain = temp;
	return (1);
}

int					get_next_line(int fd, char **line)
{
	static char		*remain[OPEN_MAX];
	char			buf[BUFFER_SIZE + 1];
	char			*line_ptr;
	size_t			readsize;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || !line)
		return (-1);
	while ((line_ptr = ft_strchr(remain[fd], '\0')) == 0)
	{
		if (readsize < 0)
			break ;
		readsize = read(fd, buf, BUFFER_SIZE);
		if((remain[fd] = ft_strncat_free(remain[fd], buf, readsize))==0)
			return (read_error(&remain[fd]));
	}
	if (line_ptr == 0)
	{
		if (readsize == 0)
			return (read_eof(line, &remain[fd]));
		else if (readsize < 0)
			return (read_error(&remain[fd]));
	}
	return (make_line(line, &remain[fd], line_ptr));
}
