#include "cub3d.h"

void		ft_sprite_store(t_game *g, int i, int j)
{
	t_list	*cur;

	cur = ft_lstnew(0);
	cur->pt.x = j;
	cur->pt.y = i;
	ft_lstadd_back(&g->spr, cur);
}