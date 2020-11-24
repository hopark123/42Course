/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:50:38 by hopark            #+#    #+#             */
/*   Updated: 2020/11/24 21:26:05 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		max(int a, int b, int c)
{
	int		temp;

	temp = a >= b ? a : b;
	return (temp >= c ? temp : c);
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
