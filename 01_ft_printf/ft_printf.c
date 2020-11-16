/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:50:38 by hopark            #+#    #+#             */
/*   Updated: 2020/11/16 17:29:27 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

struct		*infor{
	int		left;
	int		plus;
	int		blank;
	int		zero;
	int		sharp;
	int		len;
	int		width;
	int		precision;
	char	*content;
}			t_infor;

int			ft_printf(const char *format, ...)
{
	int		cnt;
	int		ctemp;
	static char *s_format;
	s_format = (char *)format;
	va_list	ap;
	va_start(ap, format);
	i = 0;
	cnt = 0;
	while (*s_format++)
	{
		if (*s_format == %)
		{
			if (ctmep = ft_parsing(&s_format[i], ap))
				cnt += ctmep;
		}
		else
		{
			ft_putchar(s_format,0);
			cnt++;
		}
	}
	va_end(ap);
}

int			ft_parsing(char **format, va_list ap)
{
	int					cnt;
	char				*ptr;
	static t_infor		*inf;
	ft_init_inf(inf);
	while (**format++)
	{
		if (ft_strchr("-+ 0#", **format))
			ft_check_flag(*format, inf);
		if (ft_strchr("123456789*", **format))
			ft_check_width(*format, inf, ap);
		if (ft_strchr(".", **format))
			ft_check_precision(*format, inf, ap);
		if (ft_strchr("cspdiuxXnfge%", **format))
		{
			ft_check_specifier(*format, inf);
			ft_print(inf, ap);
			break;
		}

	}
}

void 		ft_check_flag(char **format, s_infor infor)
{
	if (*format++ == "-")
	{
		infor.left = 1;
		return ;
	}
	if (*format++ == "+")
	{
		infor.plus = 1;
		return ;
	}
	if (*format++ == " ")
	{
		infor.blank = 1;
		return ;
	}
	if (*format++ == "0")
	{
		infor.zero = 1;
		return ;
	}
	if (*format++ == "#")
	{
		infor.sharp = 1;
		return ;
	}
}

void			ft_check_width(char **format, s_infor infor, va_list ap)
{
	int width;

	if (**format == "*")
	{
		infor.width = va_arg(ap, int);
		return ;
	}
	width = 0;
	while (ft_strchr("0123456789", **format++))
	{
		width += **foramt;
		width *= 10;
	}
	infor.width = width;
}

void			ft_check_precision(char **format, s_infor infor, va_list ap)
{
	int precision;

	**format++;
	if (**format++ == "*")
	{
		infor.precision = va_arg(ap, int);
		return ;
	}
	precision = 0;
	while (ft_strchr("0123456789", **format++))
	{
		precision += **foramt;
		precision *= 10;
	}
	infor.precision = precision;
}

void			ft_check_specifier(char **format, s_infor infor)
{
	l / h 개수 세기;
}
