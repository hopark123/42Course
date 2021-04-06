#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int			ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

int			ft_numlen(int	num)
{
	int i = 1;
	while (num /= 10)
		i++;
	return (i);
}
int			ft_hexlen(unsigned int unum)
{
	int i = 1;
	
	while (unum /= 16)
		i++;
	return (i);
}
void		ft_putstr(char *s, int num)
{
	int i = 0;

	while (i < num && s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void		ft_putnum(long long int num, int base)
{
	char *dec = "0123456789";
	char *hex = "0123456789abcdef";

	if (num < 0)
		num = -num;
	if (num >= base)
	{
		ft_putnum(num / base, base);
		ft_putnum(num % base, base);
	}
	else
	{
		if (base == 10)
			write(1, &dec[num], 1);
		else
			write(1, &hex[num], 1);
	}
}

char		*ft_strndup(char *s, int n)
{
	int		i = 0;
	char	*res;

	if (!(res = malloc(sizeof(char) * (n + 1))))
		return (0);
	while (i < n)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
	return (res);
}


int			ft_printf2(char *f, va_list ap, char type)
{
	int		width = 0;
	int		precision = 0;
	int		dot = 0;
	int		i = 0;

	while (f[i])
	{
		if ((f[i] >= '0' && f[i] <= '9') && dot == 0)
			width = width * 10 + f[i] - '0';
		else if (f[i] == '.')
			dot = 1;
		else if ((f[i] >= '0' && f[i] <= '9') && dot == 1)
			precision = precision * 10 + f[i] - '0';
		i++;
	}

	int		len = 0;
	int		ret = 0;
	char	*str;
	int		num = 0;
	unsigned int unum = 0;

	if (type == 's')
	{
		if ((str = va_arg(ap, char *)) == 0)
			str = "(null)";
		len = ft_strlen(str);
		if (!dot)
			precision = len;
		else
			if (len < precision)
				precision = len;
		i = 0;
		while (i < width - precision)
		{
			write(1, " ", 1);
			i++;
			ret++;
		}
		ft_putstr(str, precision);
		ret += precision;
	}
	else
	{
		if (type == 'd')
		{
			num = va_arg(ap, int);
			len = ft_numlen(num);
		}
		else
		{
			unum = va_arg(ap, unsigned int);
			len = ft_hexlen(unum);
		}
	if (num == 0 && unum == 0 && dot && precision == 0)
		{
			i = 0;
			while (i < width)
			{
				write(1, " ", 1);
				ret++;
				i++;
			}
			return (ret);
		}
			if (precision < len)
			precision = len;
		if (num < 0)
		{
			precision++;
			len++;
		}
		i = 0;
		while (i < width - precision)
		{
			write(1, " ", 1);
			i++;
			ret++;
		}
		if (num < 0)
			write(1, "-", 1);
		i = 0;
		while (i < precision - len)
		{
			write(1, "0", 1);
			i++;
		}
		if (type == 'd')
			ft_putnum(num, 10);
		else
			ft_putnum(unum, 16);
		ret += precision;
	}
	free(f);
	return (ret);
}
char		*ft_parsing(char *s)
{
	int		i = 0;

	while (s[i])
	{
		while ((s[i] >= '0' && s[i] <= '9') || s[i] == '.')
			i++;
		if (s[i] == 'd' || s[i] == 'x' || s[i] == 's')
			return (&s[i]);
		else
			return (NULL);
	}
	return (0);
}

int			ft_check(char *s, va_list ap)
{
	int		ret = 0;
	int		i = 0;
	char	*format;
	char	*type;

	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			type = ft_parsing(&s[i]);
			if (type)
			{
				format = ft_strndup(&s[i], type - s - i + 1);
				i += ft_strlen(format);
				ret += ft_printf2(format, ap, *type);
			}
		}
		else
		{
			write(1, &s[i], 1);
			i++;
			ret++;
		}
	}
	return (ret);
}
int			ft_printf(const char *s, ...)
{
	va_list ap;
	int ret = 0;

	if (!s)
		return (-1);
	va_start(ap, s);
	ret = ft_check((char *)s, ap);
	va_end(ap);
	return (ret);
}

