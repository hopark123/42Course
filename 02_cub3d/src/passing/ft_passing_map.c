/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_passing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:38:29 by hopark            #+#    #+#             */
/*   Updated: 2021/02/25 18:16:05 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_map_component(t_game *g, int fd)
{
	int		i;
	char	*line;
	char	**split;
	int		temp;
	
	i = 0;
	while (i < 8)
	{
		while (1)
		{
			temp = get_next_line(fd, &line);
			if (ft_strlen(line) != 0)
				break;
		}
		split = ft_split(line, ' ');
		free(line);
		if (ft_passing_type(g, split) == -1)
			return(-1);
		i++;
	}
	if (temp < 0)
		ft_exit_msg(g, "gnl error");
	return (0);
}

int			ft_txt_passing(t_game *g, int fd, t_list *list)
{
	char		*line;
	t_list		*new;
	int			max;
	int			i;
	int			temp;

	g->map.size.y = 1;
	max = 0;
	while ((temp = get_next_line(fd, &line)) >= 0)
	{
		new = ft_lstnew(line);
		ft_lstadd_back(&(list), new);
		max = ft_max(max, ft_strlen(line));
		g->map.size.y++;
		if (temp == 0)
			break;
	}
	if (temp < 0)
		ft_exit_msg(g, "gnl error");
	g->map.size.x = max;
	ft_map_making(g, list);
	return (0);
}

int			ft_txt_reading(t_game *g, int fd)
{
	char	*line;
	t_list	*list;
	int		temp;

	ft_map_component(g, fd);
	while ((temp = get_next_line(fd, &line)) >= 0)
	{
		if (ft_strlen(line) == 0)
			free(line);
		else
			break;
	}
	if (temp < 0)
		ft_exit_msg(g, "gnl error");
	list = ft_lstnew(line);

	if (ft_txt_passing(g, fd, list) == -1)
		ft_exit_msg(g, "passing error");
	
	return (0);
}

int			ft_map_making(t_game *g, t_list *list)
{
	int			i;

	if (!(g->map.m = malloc(sizeof(char *) * (g->map.size.y + 1))))
		return (-1);
	g->map.m[g->map.size.y + 1] = 0;
	i = -1;
	while (i++ < g->map.size.y)
	{
		if(!(g->map.m[i] = malloc(sizeof(char) * (g->map.size.x + 1))))
			return (-1);
		ft_memset(g->map.m[i], 'x', g->map.size.x);
		ft_memcpy(g->map.m[i], list->content, ft_strlen(list->content));
		if (list->next == 0)
			break;
		list = list->next;
	}
	ft_lstclear(&(list));
	return(0);
}