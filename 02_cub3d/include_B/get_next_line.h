/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 13:31:33 by hopark            #+#    #+#             */
/*   Updated: 2021/02/19 13:18:45 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX	10240
# endif

int			get_next_line(int fd, char **line);
int			ft_strlen(const char *s);
void		*ft_memcpy(void *dst, const void *src, int n);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strndup2(const char *s, int len);
char		*ft_strchr(const char *s, char c);
int			ft_strlen(const char *s);

#endif
