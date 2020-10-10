/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 20:32:23 by hopark            #+#    #+#             */
/*   Updated: 2020/10/10 20:42:26 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

static int			read_error(char **remain);
static int			read_eof(char **line, char **remain);
static int			make_line(char **line, char **remain, char *line_ptr);
int					get_next_line(int fd, char **line);

size_t				ft_strlen(char *s);
char				*ft_strchr(char *s, char c);
char				*ft_strncpy(char *dst, char *src, size_t size);
char				*ft_strncat_free(char *dst, char *src, size_t size);

#endif
