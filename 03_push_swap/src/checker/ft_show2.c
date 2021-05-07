/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:40:21 by hopark            #+#    #+#             */
/*   Updated: 2021/05/07 15:39:44 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 12:09:54 by hopark            #+#    #+#             */
/*   Updated: 2021/05/06 18:46:53 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_show2(t_inf *inf, char *com)
{
	t_list		*tempa;
	t_list		*tempb;
	int			flag1;
	int			flag2;
	int			i;

	//system("sleep 0.03");
	//system("clear");
	write(1, "  ", 2);
	write(1, com, ft_strlen(com));
	write(1, "\n", 1);
	write(1, "cnt : ", 6);
	ft_putnbr_fd(cnt, 1, "\x1b[30m");
	write(1, "\n", 1);
	flag1 = 0;
	flag2 = 0;
	if (inf->a_h)
		flag1 = 1;
	if (inf->b_h)
		flag2 = 1;
	tempa = inf->a_h;
	tempb = inf->b_h;

	while ((flag1 || flag2))
	{
		i = 0;
		if (flag1)
		{
			write(1, "  ", 2);
			ft_putnbr_fd(tempa->num, 1, "\x1b[30m");
			i = ft_numlen(tempa->num);
			while (i++ < 6)
				write(1, " ", 1);
			tempa = tempa->next;
			if (tempa == inf->a_h)
				flag1 = 0;
		}
		else
			while (i++ < 7)
				write(1, " ", 1);
		write(1, " | ", 3);

		if (flag2)
		{
			write(1, "  ", 2);
			ft_putnbr_fd(tempb->num, 1, "\x1b[30m");
			tempb = tempb->next;
			if (tempb == inf->b_h)
				flag2 = 0;
		}
		else
			write(1, "    ", 4);
		write(1, "\n", 1);
	}

}
