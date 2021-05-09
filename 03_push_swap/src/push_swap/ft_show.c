/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 12:09:54 by hopark            #+#    #+#             */
/*   Updated: 2021/05/09 17:57:16 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_show_head(t_inf *inf, char *com)
{
	if (inf->max <= 100)
		system("sleep 0.03");
	system("clear");
	write(1, "  ", 2);
	write(1, com, ft_strlen(com));
	write(1, "\n", 1);
	write(1, "  ", 2);
	ft_putnbr_fd(cnt, 1, "\x1b[30m");
	write(1, "\n", 1);
}

void	ft_show_a(t_inf *inf, int *flag1, t_list **tempa, t_color color)
{
	int			i;

	i = 0;
	if ((*flag1))
	{
		if ((*tempa)->chunk == -5)
			ft_putnbr_fd2((*tempa)->num, 1, color.no);
		else
			ft_putnbr_fd2((*tempa)->num, 1, color.yes);
		i = (*tempa)->num;
		while (i++ < inf->max + 3)
			write(1, "  ", 1);
		(*tempa) = (*tempa)->next;
		if ((*tempa) == inf->a_h)
			(*flag1) = 0;
	}
	else
		while (i++ < inf->max + 3)
			write(1, "  ", 1);
}

void	ft_show_b(t_inf *inf, int *flag2, t_list **tempb, t_color color)
{
	if ((*flag2))
	{
		write(1, "  ", 2);
		ft_putnbr_fd2((*tempb)->num, 1, color.yes);
		(*tempb) = (*tempb)->next;
		if ((*tempb) == inf->b_h)
			(*flag2) = 0;
	}
	else
		write(1, "    ", 4);
}

void	ft_color_init(t_inf *inf, t_color *color)
{
	color->yes = "\x1b[30m";
	color->no = "\x1b[30m";
	if (ft_strchr("c", inf->bonus))
	{
		color->yes = "\x1b[31m";
		color->no = "\x1b[32m";
	}
}

void	ft_show(t_inf *inf, char *com)
{
	t_list		*tempa;
	t_list		*tempb;
	int			flag1;
	int			flag2;
	t_color		color;

	ft_color_init(inf, &color);
	ft_show_head(inf, com);
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
		ft_show_a(inf, &flag1, &tempa, color);
		write(1, " | ", 3);
		ft_show_b(inf, &flag2, &tempb, color);
		write(1, "\n", 1);
	}
}
