/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:50:38 by hopark            #+#    #+#             */
/*   Updated: 2020/11/19 04:25:17 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s == 0 || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}

char		*ft_strchr(const char *s, int c)
{
	size_t				i;

	i = 0;
	while (s[i] != c)
	{
		if (s[i] == 0)
			return (0);
		i++;
	}
	return ((char *)s + i);
}

typedef struct		s_flag
{
	int		left;
	int		plus;
	int		blank;
	int		zero;
	int		hash;
}					t_flag;

typedef struct		s_infor
{
	t_flag	flag;
	char	type;
	int		len;
	char	i_width;
	int		width;
	char	i_precision;
	int		precision;
	char	*content;
}					t_infor;


int			ft_parsing(char **format, va_list ap, t_infor *infor);
void			ft_make_content(char **format, t_infor *infor, va_list ap);
void			ft_check_precision(char **format, t_infor *infor, va_list ap);
void			ft_check_width(char **format, t_infor *infor, va_list ap);
void			ft_check_flag(char **format, t_infor *infor);

void		ft_init_flag(t_flag *flag)
{
	flag->left = 0;
	flag->plus = 0;
	flag->blank = 0;
	flag->zero = 0;
	flag->hash = 0;
}

t_infor		*ft_init_infor(t_infor *infor)
{
	t_infor		*result;

	if (!(result = malloc(sizeof(t_infor))))
		return (0);
	ft_init_flag(&(infor->flag));
	infor->type = 0;
	infor->len = 0;
	infor->i_width = 0;
	infor->width = 0;
	infor->i_precision = 0;
	infor->precision = 0;
	infor->content = 0;
	return (result);
}

int			ft_print(char **format, va_list ap)
{
	t_infor *infor;
	int		cnt;

	infor = ft_init_infor(0);
	cnt = ft_parsing(format, ap, infor);
	ft_putstr_fd(infor->content, 0);
	free(infor->content);
	free(infor);
	return (cnt);
}

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

int			ft_parsing(char **format, va_list ap, t_infor *infor)
{
	int			cnt;
	char		*ptr;

	while (**format)
	{
		if (ft_strchr("-+ 0#", **format))
			ft_check_flag(format, infor);
		else if (ft_strchr("123456789*", **format))
			ft_check_width(format, infor, ap);
		else if (ft_strchr(".", **format))
			ft_check_precision(format, infor, ap);
		else
		{
			infor->type = **format;
			ft_make_content(format, infor, ap);
			(*format)++;
			return (ft_strlen(infor->content));
		}
	}
	return (0);
}

void			ft_check_flag(char **format, t_infor *infor)
{
	if (**format == '-')
		infor->flag.left = 1;
	else if (**format == '+')
		infor->flag.plus = 1;
	else if (**format == ' ')
		infor->flag.blank = 1;
	else if (**format == '0')
		infor->flag.zero = 1;
	else if (**format == '#')
		infor->flag.hash = 1;
	(*format)++;
	return ;
}

void			ft_check_width(char **format, t_infor *infor, va_list ap)
{
	int temp;

	temp = 0;
	if (**format == '*')
	{
		if ((infor->width = va_arg(ap, int)) <= 0)
		{
			infor->flag.left = 1;
			infor->width *= -1;
		}
		(*format)++;
		return ;
	}
	while (ft_strchr("0123456789", **format))
	{
		temp *= 10;
		temp += **format - '0';
		(*format)++;
	}
	infor->width = temp;
}

void			ft_check_precision(char **format, t_infor *infor, va_list ap)
{
	int		temp;

	temp = 0;
	if (**format == '*')
	{
		if ((infor->precision = va_arg(ap, int)) <= 0)
		{
			infor->flag.left = 1;
			infor->precision *= -1;
		}
		(*format)++;
		return ;
	}
	while (ft_strchr("0123456789", **format))
	{
		temp *= 10;
		temp += **format - '0';
		(*format)++;
	}
	infor->precision = temp;
}

void			ft_make_content(char **format, t_infor *infor, va_list ap)
{
	printf("%s", *format);
}
// 	if (infor->type == 'c')
// 		ft_printchar(char **format, t_infor infor, va_list ap);
// 	else if (infor->type == 's')
// 		ft_printchar(char **format, t_infor infor, va_list ap);
// 	else if (infor->type == 'p')
// 		ft_printchar(char **format, t_infor infor, va_list ap);
// 	else if (infor->type == 'd' || infor->type ==== 'i')
// 		ft_printchar(char **format, t_infor infor, va_list ap);
// 	else if (infor->type == 'u')
// 		ft_printchar(char **format, t_infor infor, va_list ap);
// 	else if (infor->type == 'x')
// 		ft_printchar(char **format, t_infor infor, va_list ap);
// 	else if (infor->type == 'X')
// 		ft_printchar(char **format, t_infor infor, va_list ap);
// 	else if (infor->type == 'n')
// 		ft_printchar(char **format, t_infor infor, va_list ap);
// 	else if (infor->type == 'f')
// 		ft_printchar(char **format, t_infor infor, va_list ap);
// 	else if (infor->type == 'g')
// 		ft_printchar(char **format, t_infor infor, va_list ap);
// 	else if (infor->type == 'e')
// 		ft_printchar(char **format, t_infor infor, va_list ap);
// 	else if (infor->type == 'o')
// 		ft_printchar(char **format, t_infor infor, va_list ap);
// 	else
// 		ft_printchar(char **format, t_infor infor, va_list ap);
// }
