/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:21:30 by hopark            #+#    #+#             */
/*   Updated: 2020/11/25 02:31:03 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void			ft_make_content(t_infor *infor, va_list ap)
{
	if (infor->type == 'c')
		ft_printchar(infor, ap);
	else if (infor->type == 's')
		ft_printstring(infor, ap);
	else if (infor->type == 'p')
		ft_printpoint(infor, ap);
	else if (infor->type == 'd' || infor->type == 'i')
		ft_printint(infor, ap);
	else if (infor->type == 'u')
		ft_printunsigendint(infor, ap);
	else if (infor->type == 'x' || infor->type == 'X')
		ft_printhexa(infor, ap);
	else if (infor->type == 'n')
		ft_printn(infor, ap);
	else if (infor->type == 'f')
		ft_printfloat(infor, ap);
	else if (infor->type == 'g')
		ft_printg(infor, ap);
	else if (infor->type == 'e')
		ft_printe(infor, ap);
	else
		ft_printchar(infor, ap);
}
