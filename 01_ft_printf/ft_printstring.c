/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 02:34:10 by hopark            #+#    #+#             */
/*   Updated: 2020/11/25 03:32:01 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_printstring(t_infor *infor, va_list ap)
{
	if (!infor->left && infor->zero)
		ft_printstring2(t_infor *infor, va_list ap, 0);
	ft_printstring2(t_infor *infor, va_list ap, ' ');
}

void		ft_printstring2(t_infor *infor, va_list ap, char c)
{
	int		strlen;
	char	*temp;
	char	*out;
	int		i;

	i = 0;
	temp = va_arg(ap, char *);
	strlen = (infor->precision >= 0 ? infor->precision : ft_strlen(temp);
	infor->size = max(infor->width, strlen, 0);
	out = ft_calloc_c(infor->size + 1, sizeof(char), c);
	if (!infor->flag.left)
		i = max(strlen, infor->width, 0) - strlen;
	ft_memcpy(&out[i], temp, strlen);
}
