/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 12:14:35 by hopark            #+#    #+#             */
/*   Updated: 2021/03/01 15:55:23 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_strlen2(char **s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int				ft_split_check(char **split, int num)
{
	if (ft_strlen2(split) != num)
		return (-1);
	return (1);
}

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr1;
	unsigned char		*ptr2;
	size_t				i;

	ptr1 = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	i = 0;
	if (dest == src || n == 0)
		return (dest);
	if (dest < src)
		while (i < n)
		{
			ptr1[i] = ptr2[i];
			i++;
		}
	else
		while (i < n)
		{
			ptr1[n - i - 1] = ptr2[n - i - 1];
			i++;
		}
	return (dest);
}
int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i + 1 < n)
	{
		if (c1[i] != c2[i])
			break ;
		if (c1[i] * c2[i] == 0)
			break ;
		i++;
	}
	return (c1[i] - c2[i]);
}

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		llen;

	if (*little == 0)
		return ((char *)big);
	llen = ft_strlen(little);
	i = 0;
	if (*big == 0)
		return (0);
	while (i + llen <= len)
	{
		if (ft_strncmp(big + i, little, llen) == 0)
			return ((char *)big + i);
		i++;
	}
	return (0);
}


static void	bmp_header(t_game *g, int fd)
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

static void	bmp_data(t_game *g, int fd)
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

int			ft_save_bmp(t_game *g)
{
	int		fd;

	if ((fd = open("./image.bmp", O_CREAT | O_RDWR)) == -1)
		ft_exit_msg(g, "can't (create | open) image.bmp file");
	ft_img_init(g);
	ft_update_image(g);
	bmp_header(g, fd);
	bmp_data(g, fd);
	close(fd);
	return (1);
}

int		extention_check(char *path)
{
	int		len;

	if ((len = ft_strlen(path)) < 4)
		return (-1);
	if (path[len - 1] == 'b' && path[len - 2] == 'u' \
		&& path[len - 3] == 'c' && path[len - 4] == '.')
		return (1);
	return (-1);
}


int			main(int ac, char **av)
{
	t_game			g;
	int				fd;
	int				flag;
	
	ft_memset(&g, 0, sizeof(t_game));
	if (ac < 2)
		ft_exit_msg(&g, "input map file");
	if (extention_check(av[1]) == -1)
		ft_exit_msg(&g, "input |.cub| file");
	if ((fd = open(av[1] , O_RDONLY)) == -1)
		ft_exit_msg(&g, "open error");
	if (ac > 2)
		flag = !ft_memcmp(av[2], "--save", 6);
	ft_txt_reading(&g, fd);
	ft_map_init(&g);
	ft_window_init(&g);
	ft_img_init(&g);
	if (flag == 1)
		return (ft_save_bmp(&g));
	mlx_hook(g.win, X_EVENT_KEY_PRESS, 0, &ft_key_press, &g);
	mlx_hook(g.win, X_EVENT_KEY_RELEASE, 0, &ft_key_release, &g);
	mlx_loop_hook(g.mlx, &ft_main_loop, &g);
	mlx_loop(g.mlx);
	return (0);
}