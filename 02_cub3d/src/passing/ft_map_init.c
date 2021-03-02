/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:38:09 by hopark            #+#    #+#             */
/*   Updated: 2021/03/01 16:04:36 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			g_dx[4] = {0, 0, -1, 1};
int			g_dy[4] = {-1, 1, 0, 0};

void			ft_map_init(t_game *g)
{
	int		i;
	int		j;

	i = -1;

	g->inpos = 0;
	while (++i < g->map.size.y)
	{
		j = -1;
		while (++j < g->map.size.x)
		{
			if (ft_strchr(" 012NSWEx", g->map.m[i][j]) == 0)
				ft_exit_msg(g, "strange map value");
			else if (ft_strchr("NSWE", g->map.m[i][j]))
			{
				ft_player_init(g, i, j, g->map.m[i][j]);
				if (ft_map_valid(g, i, j) == -1)
					ft_exit_msg(g, "not surrand wall");
			}
			else if (ft_strchr("2", g->map.m[i][j]))
			{
				ft_sprite_store(g, i, j);
				g->map.cnt_sprite++;
			}
		}
	}
	if (g->inpos != -1)
		ft_exit_msg(g, "map error2");
}

int			ft_dfs(t_game *g, int i, int j, char **dfs)
{
	int			k;
	int			tx;
	int			ty;
	
	if (g->map.m[i][j] == ' ')
	{
		return (-1);
	}
	dfs[i][j] = '2';
	k = 0;
	while (k < 4)
	{
		ty = i + g_dy[k];
		tx = j + g_dx[k];
		if (ty >= 0 && ty < g->map.size.y && tx >= 0 && tx < g->map.size.x)
			if (g->map.m[ty][tx] != '1' && dfs[ty][tx] == '0')
				if (ft_dfs(g, ty, tx, dfs) == -1)
					ft_exit_msg(g, "not surrand wall");
		k++;
	}
	return (0);
}

int				ft_dfs_check(t_game *g, char **dfs)
{
	int			k;
	
	k = 0;
	while (k < g->map.size.x)
	{
		if (dfs[0][k] == '2' || dfs[g->map.size.y - 1][k] == '2')
			return (-1);
		k++;
	}	
	k = 0;
	while (k < g->map.size.y)
	{	
		if (dfs[k][0] == '2' || dfs[k][g->map.size.x - 1] == '2')
			return (-1);
		k++;
	}
	return(0);
}

int					ft_map_valid(t_game *g, int i, int j)
{
	int			k;
	char		**dfs;
	
	if (!(dfs = malloc(sizeof(char *) * g->map.size.y + 1)))
		ft_exit_msg(g, "malloc error");
	k = 0;
	while (k < g->map.size.y)
	{	
		if (!(dfs[k] = malloc(sizeof(char) * g->map.size.x + 1)))
			ft_exit_msg(g, "malloc error");
		ft_memset(dfs[k], '0', g->map.size.x);
		dfs[k][g->map.size.x] = 0;
		k++;
	}
	if (ft_dfs(g, i, j, dfs) == -1)
		ft_exit_msg(g, "not surrand wall");
	k = ft_dfs_check(g, dfs);
	ft_free2(dfs, g->map.size.y);
	return (k);
}
