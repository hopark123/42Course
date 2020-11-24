/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:25:44 by hopark            #+#    #+#             */
/*   Updated: 2020/11/25 03:32:13 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void		ft_printint(t_infor *infor, va_list ap)
{
	if (!infor->flag.left && infor->precision < 0 && infor->flag.zero)
		ft_printint2(t_infor *infor, va_list ap, 0);
	ft_printint2(t_infor *infor, va_list ap, ' ');
}

void		ft_printint2(t_infor *infor, va_list ap, char c)
{
	int		number;

	if ((number = va_arg(ap, int)) < 0)
	{
		number *= -1;
		infor->nega = 1;
	}
	infor->len = ft_int_len(number);
	infor->size = max(infor->len, infor->width, infor->precision);
	if (max > infor->len && max > infor->precision)
	{
		if (infor->flag.left)
			ft_int_nz_wl(infor, number, c);
		ft_int_nz_wr(infor, number, c);
	}
	else if (infor->plus || infor->blank || infor->nega)
		ft_int_nz_sign(infor, number, c);
	ft_int_nz_nsign(infor, number, c);
}

void		ft_int_nz_wl(t_infor *infor, int number, char c)
{
	char		*temp;
	char		*out;
	int			i;
	int			j;

	i = 0;
	j = 0;
	out = ft_calloc_c(infor->size + 1, sizeof(char), c);
	temp = itoa(number);
	if (infor->nega)
		out[i++] = '-';
	else if (infor->flag.plus)
		out[i++] = '+';
	else if (infor->flag.blank)
		out[i++] = ' ';
	while (j++ < infor->precision - infor->len)
		out[i++] = '0';
	ft_memcpy(&out[i], temp, strlen(temp));
	infor->content = out;
	free(temp);
}

void		ft_int_nz_wr(t_infor *infor, int number, char c)
{
	char		*temp;
	char		*out;
	int			i;
	int			j;

	i = infor->width - max(infor->precision, infor->len, 0) + 1;
	j = 0;
	out = ft_calloc_c(infor->size + 1, sizeof(char), c);
	temp = itoa(number);
	if (infor->nega)
		out[i++] = '-';
	else if (infor->flag.plus)
		out[i++] = '+';
	else
		out[i++] = ' ';
	while (j++ < infor->precision - infor->len)
		out[i++] = '0';
	ft_memcpy(&out[i], temp, strlen(temp));
	infor->content = out;
	free(temp);
}

void		ft_int_nz_nsign(t_infor *infor, int number, char c)
{
	char		*temp;
	char		*out;
	int			i;
	int			j;

	i = 0;
	j = 0;
	temp = itoa(number);
	out = ft_calloc_c(infor->size + 1, sizeof(char), c);
	while (j++ < infor->precision - infor->len)
		out[i++] = '0';
	ft_memcpy(&out[i], temp, strlen(temp));
	infor->content = out;
	free(temp);
}

void		ft_int_nz_sign(t_infor *infor, int number, char c)
{
	char		*temp;
	char		*out;
	int			i;
	int			j;

	i = 0;
	j = 0;
	infor->size++;
	temp = itoa(number);
	out = ft_calloc_c(infor->size + 1, sizeof(char), c);
	if (infor->nega)
		out[i++] = '-';
	else if (infor->flag.plus)
		out[i++] = '+';
	else
		out[i++] = ' ';
	while (j++ < infor->precision - infor->len)
		out[i++] = '0';
	ft_memcpy(&out[i], temp, strlen(temp));
	infor->content = out;
	free(temp);
}
