/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   passing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:42:36 by hopark            #+#    #+#             */
/*   Updated: 2021/03/01 14:33:43 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PASSING_H
# define PASSING_H

# include "cub3d_type.h"
# include "utils.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

void			ft_map_init(t_game *g);
int				ft_dfs(t_game *g, int i, int j, char **dfs);
int				ft_dfs_check(t_game *g, char **dfs);
int				ft_map_valid(t_game *g, int i, int j);
void			ft_map_component(t_game * g, int fd);
void			ft_map_passing(t_game *g, int fd, t_list *list);
void			ft_txt_reading(t_game *g, int fd);
void			ft_map_making(t_game *g, t_list *list);
void 			ft_passing_type(t_game *g, char **split);
int				ft_component_check(t_game	*g, int num);
void			ft_player_init(t_game *g, int i, int j, char c);
unsigned int	ft_RGB_check(t_game *g, char **split, int num);
void			ft_sprite_store(t_game *g, int i, int j);

#endif