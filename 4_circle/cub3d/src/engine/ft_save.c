/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:57:21 by hopark            #+#    #+#             */
/*   Updated: 2021/03/08 15:18:10 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		bmp_header(t_game *g, int fd)
{
	int		tmp;
	char	header[BITMAPFILEHEADER];
	char	info[BITMAPINFOHEADER];

	ft_memset(&header, 0, BITMAPFILEHEADER);
	ft_memset(&info, 0, BITMAPINFOHEADER);
	ft_memmove(&header[0], "BM", 2);
	tmp = BITMAPFILEHEADER + BITMAPINFOHEADER +
		(g->img.bpp / 8) * g->img.width * g->img.height;
	ft_memmove(&header[2], &tmp, 4);
	tmp = BITMAPFILEHEADER + BITMAPINFOHEADER;
	ft_memmove(&header[10], &tmp, 4);
	write(fd, header, BITMAPFILEHEADER);
	tmp = BITMAPINFOHEADER;
	ft_memmove(&info[0], &tmp, 4);
	ft_memmove(&info[4], &g->img.width, 4);
	ft_memmove(&info[8], &g->img.height, 4);
	tmp = 1;
	ft_memmove(&info[12], &tmp, 2);
	ft_memmove(&info[14], &g->img.bpp, 2);
	write(fd, info, BITMAPINFOHEADER);
}

static void		bmp_data(t_game *g, int fd)
{
	int		x;
	int		y;

	y = g->img.height;
	while (y-- > 0)
	{
		x = -1;
		while (++x < g->img.width)
			write(fd, &g->img.data[y * g->img.line + x], 4);
	}
}

int				ft_save_bmp(t_game *g)
{
	int		fd;

	if ((fd = open("./image.bmp", O_CREAT | O_RDWR)) == -1)
		ft_exit_msg(g, "can't (create | open) image.bmp file", 0);
	ft_img_init(g);
	ft_update_image(g);
	bmp_header(g, fd);
	bmp_data(g, fd);
	close(fd);
	return (1);
}
