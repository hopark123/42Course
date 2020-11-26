/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:37:17 by hopark            #+#    #+#             */
/*   Updated: 2020/11/26 20:02:44 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

void		ft_bzero_c(void *s, int n, char c);
void		*ft_calloc_c(int count, int size, char c);
int			ft_int_len(int n);
char		*ft_itoa(int n);
int			ft_max(int a, int b, int c);
void		*ft_memcpy(void *dest, const void *src, int n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strchr(const char *s, int c);
int			ft_strlen(const char *s);

#endif
