/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:35:56 by hopark            #+#    #+#             */
/*   Updated: 2021/05/06 14:32:01 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

 int				main(int ac, char **av)
 {
	static t_inf	*inf;
	if (!(inf = malloc(sizeof(t_inf))))
		return (ERROR);
	ft_make_list(ac, av, inf);
	ft_show(inf, "start");
	ft_sort_a(inf, 0);
	ft_show(inf, "end");
	//get_next_line()
}