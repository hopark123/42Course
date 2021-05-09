/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:35:56 by hopark            #+#    #+#             */
/*   Updated: 2021/05/09 14:16:31 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	main(int ac, char **av)
{
	static t_inf	*inf;
	char			*line;
	int				res;
	int				i;

	if (ac < 2)
		return (0);
	if (!ft_malloc(&inf, sizeof(t_inf)))
		return (ERROR);
	if (ac ==  2)
		res = ft_make_split(ac, av, inf);
	else
		res = ft_make_list(ac, av, inf);
	if (res == ERROR)
	{
		write(1, "Error", 5);
		return (0);
	}
	res = SUCESS;
	while (get_next_line(0, &line) >= 0)
	{
		if (ft_strlen(line) == 0)
			break;
		if (ft_action2(inf, line) == -1)
			res = ERROR;
	}
	if (ft_is_ascending(inf->a_h) && !inf->b_h && res == SUCESS)
		write(1,"OK\n", 4);
	else
	{
		write(1,"NO\n", 4);
	}
	return (0);
}
