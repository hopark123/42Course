/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:50:38 by hopark            #+#    #+#             */
/*   Updated: 2020/11/24 21:17:25 by hopark           ###   ########.fr       */
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
	char		left;
	char		plus;
	char		blank;
	char		zero;
	char		hash;
}					t_flag;

typedef struct		s_infor
{
	t_flag	flag;
	char	type;
	int		len;
	int		width;
	int		precision;
	char	**content;
	int		size;
}					t_infor;


void			ft_printint(t_infor *infor, va_list ap);
int			ft_parsing(char **format, va_list ap, t_infor *infor);
void			ft_make_content(t_infor *infor, va_list ap);
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
	ft_init_flag(&(result->flag));
	result->type = 0;
	result->len = 0;
	result->width = 0;
	result->precision = 0;

	result->content = 0;
	return (result);
}

int			ft_print(char **format, va_list ap)
{
	t_infor *infor;
	int		cnt;

	infor = ft_init_infor(0);
	cnt = ft_parsing(format, ap, infor);
	ft_putstr_fd(*(infor->content), 0);
	free(*(infor->content));
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
		{
			ft_check_flag(format, infor);
		}
		else if (ft_strchr("123456789*", **format))
			ft_check_width(format, infor, ap);
		else if (ft_strchr(".", **format))
			ft_check_precision(format, infor, ap);
		else
		{
			infor->type = **format;
			ft_make_content(infor, ap);
			(*format)++;
			ft_putstr_fd(*(infor->content), 1);
			return (ft_strlen(*(infor->content)));
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

	(*format)++;
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

void			ft_make_content(t_infor *infor, va_list ap)
{
	// if (infor->type == 'c')
	// 	ft_printchar(infor, ap);
	// else if (infor->type == 's')
	// 	ft_printstring(infor, ap);
	// else if (infor->type == 'p')
	// 	ft_printpoint(infor, ap);
	// else if (infor->type == 'd' || infor->type == 'i')
		ft_printint(infor, ap);
	// else if (infor->type == 'u')
	// 	ft_printunsigendint(infor, ap);
	// else if (infor->type == 'x' || infor->type == 'X')
	// 	ft_printhexa(infor, ap);
	// else if (infor->type == 'n')
	// 	ft_printn(infor, ap);
	// else if (infor->type == 'f')
	// 	ft_printfloat(infor, ap);
	// else if (infor->type == 'g')
	// 	ft_printg(infor, ap);
	// else if (infor->type == 'e')
	// 	ft_printe(infor, ap);
	// else
	// 	ft_printchar(infor, ap);
}


int		max(int a, int b, int c)
{
	int		temp;

	temp = a >= b ? a : b;
	return (temp >= c ? temp : c);
}




void		ft_bzero_c(void *s, int n, char c)
{
	unsigned char *ptr;

	ptr = (unsigned char*)s;
	while (n-- > 0)
	{
		*(ptr++) = c;
	}
}

void		*ft_calloc_c(int count, int size, char c)
{
	void	*result;

	result = malloc(size * count);
	if (result == 0)
		return (0);
	ft_bzero_c(result, size * count, c);
	return (result);
}


int			ft_intlen(const int num)
{
	int		cnt;
	int		temp;

	temp = (int)num;
	cnt = 1;
	if (num < 0)
	{
		cnt++;
		temp*=-1;
	}
	while (temp > 10)
	{
		temp /= 10;
		cnt++;
	}
	return (temp);
}
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *ptr1;
	unsigned char *ptr2;

	if (!dest && !src)
		return (0);
	ptr1 = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	while (n-- > 0)
	{
		*(ptr1++) = *(ptr2++);
	}
	return (dest);
}
char				*ft_signitoa(int n)
{
	int		len;
	int		i;
	long long	n2;
	char		*result;

	len = ft_intlen(n) + 1;
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	result[len] = 0;
	i = 0;
	n2 = n < 0 ? (long long)n * -1 : (long long)n;
	while (i < len)
	{
		result[len - i - 1] = n2 % 10 + '0';
		n2 /= 10;
		i++;
	}
	if (n < 0)
		result[0] = '-';
	else
		result[0] = '+';
	return (result);
}


void		ft_intleft(t_infor *infor, va_list ap)
{
	int		number;
	char	*out;
	char	*temp;
	number = va_arg(ap, int);
	infor->len = ft_intlen(number);
	temp = ft_signitoa(number);

	if (infor->flag.plus || infor->flag.plus)
	{
		infor->len++;
		temp++;
	}

	infor->size = max(infor->len, infor->width, infor->precision);
	out = (char *)ft_calloc_c(infor->size, sizeof(char), ' ');

	ft_memcpy(out, temp, sizeof(out));

	free(temp);
	if (infor->flag.blank)
		out[0] = ' ';
	printf("%s", *(infor->content));
}

void		ft_printint(t_infor *infor, va_list ap)
{
	if (infor->flag.left)
		ft_intleft(infor, ap);
}




int main()
{
	ft_printf("%-6d\n", -3);
}
