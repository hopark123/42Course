/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_store.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:33:26 by hopark            #+#    #+#             */
/*   Updated: 2021/03/08 17:02:43 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_sprite_store(t_game *g, int i, int j)
{
	t_list	*cur;

	if ((cur = ft_lstnew(0)) == 0)
		ft_exit_msg(g, "sprite error", 0);
	cur->pt.x = j + 0.5;
	cur->pt.y = i + 0.5;
	ft_lstadd_back(&g->spr, cur);
}
