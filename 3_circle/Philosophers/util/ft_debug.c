/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:21:50 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/23 19:25:08 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	test_str(char *type, char *str)
{
	ft_putstr_fd("(", 2, 0);
	ft_putstr_fd(type, 2, 0);
	ft_putstr_fd(")", 2, 0);
	ft_putstr_fd("[", 2, 0);
	ft_putstr_fd(str, 2, 0);
	ft_putstr_fd("]\n", 2, 0);
}

void	test_str2(char *type, char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putstr_fd("(", 2, 0);
		ft_putstr_fd(type, 2, 0);
		ft_putstr_fd(")", 2, 0);
		ft_putstr_fd("[", 2, 0);
		ft_putstr_fd(str[i], 2, 0);
		ft_putstr_fd("]\n", 2, 0);
		i++;
	}
}

void	test_int(char *type, int num)
{
	ft_putstr_fd("(", 2, 0);
	ft_putstr_fd(type, 2, 0);
	ft_putstr_fd(")", 2, 0);
	ft_putstr_fd("[", 2, 0);
	ft_putnbr_fd(num, 2, 0);
	ft_putstr_fd("]\n", 2, 0);
}

void	test_list(char *type, t_list *list)
{
	t_list	*temp;

	temp = list;
	while (temp)
	{
		fprintf(stderr, "(%s) b[%ld] | ", type, temp->id);
		temp = temp->next;
	}
}

void	test_spot(char	*str)
{
	ft_putstr_fd(str, 2, 0);
	ft_putstr_fd("\n", 2, 0);
}
