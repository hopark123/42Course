/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:35:56 by hopark            #+#    #+#             */
/*   Updated: 2021/05/10 20:30:28 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_checker(t_inf *inf)
{
	int		res;
	char	*line;

	res = SUCESS;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strlen(line) == 0 || ft_action_c(inf, line) == -1)
		{
			ft_exit(inf, "Error3\n", 2);
			return ;
		}
	}
	if (ft_is_ascending(inf->a_h) && !inf->b_h && res == SUCESS)
		ft_exit(inf, "OK\n", 1);
	else
		ft_exit(inf, "KO\n", 1);
}

int	main(int ac, char **av)
{
	static t_inf	*inf;
	int				res;

	if (ac < 2)
		return (0);
	if (!ft_malloc(&inf, sizeof(t_inf)))
		return (ERROR);
	if (ac == 2)
		res = ft_make_split(av, inf);
	else
		res = ft_make_list(av, inf);
	if (res == ERROR)
	{
		ft_exit(inf, "Error1\n", 2);
		return (0);
	}
	ft_checker(inf);
	ft_exit(inf, "Error2\n", 2);
	return (0);
}
