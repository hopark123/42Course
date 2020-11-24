/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intleft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:23:43 by hopark            #+#    #+#             */
/*   Updated: 2020/11/24 21:24:51 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}
