/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 20:32:23 by hopark            #+#    #+#             */
/*   Updated: 2020/10/10 21:24:16 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

size_t				ft_strlen(char *s);
char				*ft_strchr(char *s, char c);
char				*ft_strncpy(char *dst, char *src, size_t size);
char				*ft_strncat_free(char *dst, char *src, size_t size);
int					get_next_line(int fd, char **line);
#endif
