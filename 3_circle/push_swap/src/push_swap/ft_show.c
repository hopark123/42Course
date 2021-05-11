/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 12:09:54 by hopark            #+#    #+#             */
/*   Updated: 2021/05/11 16:02:31 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_show_head(t_inf *inf, char *com)
{
	if (inf->max <= 200)
		system("sleep 0.05");
	system("clear");
	write(1, com, ft_strlen(com));
	write(1, "\n", 1);
	ft_putnbr_fd(g_cnt, 1, 0);
	write(1, "\n", 1);
}

void	ft_show_a(t_inf *inf, int *flag1, t_list **tempa, t_color color)
{
	int			i;
	int			k;

	i = 0;
	k = 0;
	if (inf->min < 0)
		k = -1 * inf->min + 1;
	if ((*flag1))
	{
		if ((*tempa)->chunk == -5)
			ft_putnbr_fd2((*tempa)->num + k, 1, color.yes);
		else
			ft_putnbr_fd2((*tempa)->num + k, 1, color.no);
		i = (*tempa)->num;
		while (i++ < inf->max + 3)
			write(1, " ", 1);
		(*tempa) = (*tempa)->next;
		if ((*tempa) == inf->a_h)
			(*flag1) = 0;
	}
	else
		while (i++ < inf->max + k + 3)
			write(1, " ", 1);
}

void	ft_show_b(t_inf *inf, int *flag2, t_list **tempb, t_color color)
{
	int			k;

	k = 0;
	if (inf->min < 0)
		k = -1 * inf->min + 1;
	if ((*flag2))
	{
		write(1, "  ", 2);
		ft_putnbr_fd2((*tempb)->num + k, 1, color.no);
		(*tempb) = (*tempb)->next;
		if ((*tempb) == inf->b_h)
			(*flag2) = 0;
	}
}

void	ft_color_init(t_inf *inf, t_color *color)
{
	color->yes = "\x1b[30m";
	color->no = "\x1b[30m";
	if (ft_strchr("c", inf->bonus))
	{
		color->yes = "\x1b[32m";
		color->no = "\x1b[31m";
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
