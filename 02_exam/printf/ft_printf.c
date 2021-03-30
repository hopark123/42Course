/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:48:22 by hopark            #+#    #+#             */
/*   Updated: 2021/03/20 20:23:37 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

void			ft_putnbr(long long num, int flag)
void			ft_putnstr(char *s, int num)
int				ft_strlen(char *s)
int				ft_strnum(int num)
int				ft_strhexa(unsigned int unum)
char			*ft_strndup(char *s, int num)

int				ft_print(char **format, va_list ap, char type)
char			*ft_checktype(char **format)
int				ft_passing(char **format, va_list ap)

int				ft_printf(const char **format, ...)
{
	va_list ap;
}
