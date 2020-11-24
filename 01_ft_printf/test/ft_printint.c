/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:03:38 by hopark            #+#    #+#             */
/*   Updated: 2020/11/24 22:20:21 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

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

int			ft_int_len(int n)
{
	size_t		len;
	long long	n2;

	len = 1;
	n2 = (long long)n;
	if (n2 < 0)
		n2 *= -1;
	while (n2 >= 10)
	{
		len++;
		n2 /= 10;
	}
	return (++len);
}

char		*ft_signitoa(int n)
{
	int			len;
	int			i;
	long long	n2;
	char		*result;

	len = ft_int_len(n);
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

void		ft_printint(t_infor *infor, va_list ap)
{
	if (infor->flag.left)
		ft_intleft(infor, ap);
	ft_intright(infor, ap);
}

void		ft_intleft(t_infor *infor, va_list ap)
{
	int		number;
	char	*out;
	char	*temp;

	number = va_arg(ap, int);
	infor->len = ft_int_len(number) - 1;
	temp = ft_signitoa(number);
	if (!infor->flag.plus && !infor->flag.blank && number >= 0)
	{
		infor->len--;
		temp++;
	}
	infor->size = max(infor->len, infor->width, infor->precision);
	out = (char *)ft_calloc_c(infor->size, sizeof(char), ' ');
	ft_memcpy(out, temp);
	free(temp);
	if (infor->flag.blank)
		out[0] = ' ';
	infor->content = &out;
}
