/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:35:56 by hopark            #+#    #+#             */
/*   Updated: 2021/07/13 19:38:01 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_checker(t_inf *inf)
{
	int		res;
	char	*line;

	res = SUCCESS;
	ft_putstr_fd("gnl start\n", 2, 0);
	while (get_next_line(0, &line) > 0)
	{
		ft_putstr_fd("[", 2, 0);
		ft_putstr_fd(line, 2, 0);
		ft_putstr_fd("]\n", 2, 0);
		if (ft_strlen(line) == 0 || ft_action_c(inf, line) == -1)
		{
			ft_free(line);
			ft_exit(inf, "Error\n", 2);
			return ;
		}
	}
	ft_free(line);
	ft_putstr_fd("gnl end\n",2,0);
	if (ft_is_ascending(inf->a_h) && !inf->b_h && res == SUCCESS)
		ft_exit(inf, "OK\n", 1);
	else
		ft_exit(inf, "KO\n", 1);
}

int	main(int ac, char **av)
{
	static t_inf	*inf;
	int				res;

	if (ac < 2)
	{
		write(2, "Error\n", 7);
		return (0);
	}
	if (!ft_malloc(&inf, sizeof(t_inf)))
	{
		write(2, "Error\n", 7);
		return (0);
	}
	ft_inf_init(inf);
	if (ac == 2)
		res = ft_make_split(av, inf);
	else
		res = ft_make_list(av, inf);
	if (res == ERROR)
	{
		ft_exit(inf, "Error\n", 2);
		return (0);
	}
	ft_checker(inf);
	return (0);
}
