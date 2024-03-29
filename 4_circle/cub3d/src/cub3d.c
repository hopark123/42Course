/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 12:14:35 by hopark            #+#    #+#             */
/*   Updated: 2021/03/09 13:32:37 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			main(int ac, char **av)
{
	t_game			g;
	int				fd;
	int				flag;

	ft_memset(&g, 0, sizeof(t_game));
	if (ac < 2 || ac > 3)
		ft_exit_msg(&g, "input error", 0);
	if (extention_check(av[1]) == -1)
		ft_exit_msg(&g, "input |.cub| file", 0);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_exit_msg(&g, "open error", 0);
	if (ac > 2 && (flag = !ft_memcmp(av[2], "--save", 6)) != 1)
		ft_exit_msg(&g, "input error", 0);
	ft_txt_reading(&g, fd);
	ft_map_init(&g);
	ft_window_init(&g);
	ft_img_init(&g);
	if (flag == 1)
		return (ft_save_bmp(&g));
	mlx_hook(g.win, X_EVENT_KEY_PRESS, 0, &ft_key_press, &g);
	mlx_hook(g.win, X_EVENT_KEY_RELEASE, 0, &ft_key_release, &g);
	mlx_hook(g.win, X_EVENT_KEY_EXIT, 0, &ft_exit_window, &g);
	mlx_loop_hook(g.mlx, &ft_main_loop, &g);
	mlx_loop(g.mlx);
	return (0);
}
