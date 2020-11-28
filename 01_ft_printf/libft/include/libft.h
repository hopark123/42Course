/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:37:17 by hopark            #+#    #+#             */
/*   Updated: 2020/11/29 02:37:25 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

void				ft_bzero_c(void *s, int n, char c);
void				*ft_calloc_c(int count, int size, char c);
int					ft_int_len(long long n);
int					ft_uint_len(unsigned long long n);
char				*ft_itoa(long long n);
char				*ft_llmin(char *result);
char				*ft_uitoa(unsigned long long n);
long long			ft_max(long long a, long long b, long long c);
long long			ft_min(long long a, long long b, long long c);
unsigned long long	ft_umax(unsigned long long a, unsigned long long b, unsigned long long c);
unsigned long long	ft_umin(unsigned long long a, unsigned long long b, unsigned long long c);
void				*ft_memcpy(void *dest, const void *src, int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd, int num);
char				*ft_strchr(const char *s, int c);
int					ft_strlen(const char *s);

#endif
