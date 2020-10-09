/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 20:59:49 by hopark            #+#    #+#             */
/*   Updated: 2020/10/09 18:15:36 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			get_next_line(int fd, char **line)
{
	static		remain[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	size_t		readsize;

	while (ft_strchr(remain[fd], '\0') == 0)
	{
		readsize = read(fd, buf, BUFFER_SIZE)
	}
}
