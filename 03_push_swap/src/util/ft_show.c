/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 12:09:54 by hopark            #+#    #+#             */
/*   Updated: 2021/05/03 12:22:44 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int				ft_show(t_inf *inf, char *com)
{
	t_list		*tempa;
	t_list		*tempb;
	int			flag1;
	int			flag2;
	// system("clear");
	write(1, com, ft_strlen(com));
	write(1,"\n",1);
	flag1 = 0;
	flag2 = 0;
	if (inf->a_h)
		flag1 = 1;
	if (inf->b_h)
		flag2 = 1;
	tempa = inf->a_h;
	tempb = inf->b_h;
	int j = 0;
	//if (tempa)
	//	printf("a : %d   \n", tempa->num);
	//if (tempb)
	//	printf("b : %d   \n", tempb->num);
	while ((flag1 || flag2))
	{
		if (flag1)
		{
			ft_putnbr_fd(tempa->num, 1);
			write(1, " : ", 3);
			ft_putnbr_fd(tempa->chunk, 1);
			tempa = tempa->next;
			if (tempa == inf->a_h)
				flag1 = 0; 
		}
		else
			write(1, "     ", 6);
		write(1, " | ", 3);
		if (flag2)
		{
			ft_putnbr_fd(tempb->num, 1);
			write(1, " : ", 3);
			ft_putnbr_fd(tempb->chunk, 1);
			tempb = tempb->next;
			if (tempb == inf->b_h)
				flag2 = 0; 
		}
		else
		{
			write(1, "    ", 4);
		}

		write(1, "\n", 1);
	}
	write(1, "    ", 4);
	ft_putnbr_fd(cnt, 1);
	write(1, "    \n", 5);

}