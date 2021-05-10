/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:35:56 by hopark            #+#    #+#             */
/*   Updated: 2021/05/09 16:35:40 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_checker(t_inf *inf)
{
	int		res;
	char	*line;
	int		i;

	res = SUCESS;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strlen(line) == 0 || ft_action_c(inf, line) == -1)
		{
			write(1, "Error\n", 6);
			return ;
		}
	}
	if (ft_is_ascending(inf->a_h) && !inf->b_h && res == SUCESS)
		write(1, "OK\n", 4);
	else
		write(1, "KO\n", 4);
}

int	main(int ac, char **av)
{
	static t_inf	*inf;
	int				res;
	int				i;

	if (ac < 2)
		return (0);
	if (!ft_malloc(&inf, sizeof(t_inf)))
		return (ERROR);
	if (ac == 2)
		res = ft_make_split(ac, av, inf);
	else
		res = ft_make_list(ac, av, inf);
	if (res == ERROR)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	ft_checker(inf);
	return (0);
}
