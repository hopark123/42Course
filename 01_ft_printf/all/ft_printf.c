/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:19:38 by hopark            #+#    #+#             */
/*   Updated: 2020/11/26 20:50:00 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	int		cnt;
	int		ctemp;
	char	*a_format;
	va_list	ap;

	a_format = (char *)format;
	va_start(ap, format);
	cnt = 0;
	while (*a_format)
	{
		if (*a_format == '%')
		{
			a_format++;
			if ((ctemp = ft_print(&a_format, ap)) == -1)
				return (-1);
			cnt += ctemp;
		}
		else
		{
			ft_putchar_fd(*a_format++, 0);
			cnt++;
		}
	}
	va_end(ap);
	return (cnt);
}

int			ft_print(char **format, va_list ap)
{
	t_infor	*infor;
	int		cnt;

	infor = ft_init_infor(0);
	cnt = ft_parsing(format, ap, infor);
	ft_putstr_fd((infor->content), 0);
	free(infor->content);
	free(infor);
	return (cnt);
}
