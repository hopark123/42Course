/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:21:50 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/13 18:29:06 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	test_str(char *type, char *str)
{
	fprintf(stderr, "(%s) [%s]\n", type, str);
}

void	test_str2(char *type, char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		fprintf(stderr, "(%s) [%s]\n", type, str[i]);
		i++;
	}
}

void	test_int(char *type, int num)
{
	fprintf(stderr, "(%s) [%d]\n", type, num);
}

void	test_list(char *type, t_list *list)
{
	t_list	*temp;

	temp = list;
	while (temp)
	{
		fprintf(stderr, "(%s) [%s]\n", type, temp->str);
		temp = temp->next;
	}
}

void	test_spot(char	*str)
{
	ft_putstr_fd(str, 2, 0);
	ft_putstr_fd("\n", 2, 0);
}
