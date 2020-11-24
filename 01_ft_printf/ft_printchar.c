/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 01:48:06 by hopark            #+#    #+#             */
/*   Updated: 2020/11/25 02:42:09 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_printchar(t_infor *infor, va_list ap)
{
	if (!infor->left && !infor->precision && infor->zero)
		ft_printchar2(t_infor *infor, va_list ap, 0);
	ft_printchar2(t_infor *infor, va_list ap, ' ');

}

void		ft_printchar2(t_infor *infor, va_list ap, char c)
{
	char	*out;
	int		i

	n > 0 ?
	i = 0;
	infor->size = infor->precision ? 1 : max(infor->width, 1, 0);
	out = ft_calloc_c(infor->size + 1, sizeof(char), c);
	if (!infor->left)
		i = size - 1;
	out[i] = (char)va_arg(ap, int);
	infor->content = out;
}
