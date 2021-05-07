/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:35:56 by hopark            #+#    #+#             */
/*   Updated: 2021/05/07 16:37:00 by hopark           ###   ########.fr       */
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
	ft_memset(&inf, 0, sizeof(t_inf));
	ft_make_list(ac, av, inf);
	res = SUCESS;
	while (get_next_line(0, &line))
	{
		if (ft_strlen(line) == 0)
			break;
		if (ft_action2(inf, line) == -1)
			res = ERROR;
	}
	if (ft_is_ascending(inf->a_h) && !inf->b_h && res == SUCESS)
		write(1,"OK\n", 4);
	else
		write(1,"KO\n", 4);
	return (0);
}
