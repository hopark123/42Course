#include "../mlx/mlx.h"
#include <stdio.h>
#include "../gnl/get_next_line.h"
#include "include/cub3d_type.h"
#include <stdlib.h>
#include <math.h>
#define _USE_MATH_DEFINES

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

#define IMG_WIDTH 800
#define IMG_HEIGHT 600

#define TEXTURE_SIZE 64
#define SPRITE_SIZE 64
#define SPRITE_WIDTH 64

char	*file_component[9] = {"R", "NO", "SO", "WE", "EA", "S", "F", "C"};
int minimap = 5;
int TILESIZE = 15;
int mapx = 16, mapy = 8;
float FOV_ANGLE = 60 * (M_PI / 180);
int WALL_STRIP_WIDTH = 1;
// int	NUM_RAYS = WIN_WIDTH / WALL_STRIP_WIDTH;
int NUM_RAYS = 800;

int map[] = {
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};

#define numSprites 10
float ZBUFFER[800];
t_sprite sprite[numSprites] = {
	{7, 5 ,4},
	{2.5, 3.5 ,4},
	{3, 3 ,4},
	{5, 3 ,5},
	{5, 3.2 ,5},
	{6, 3.5 ,5},
	{4, 3.7 ,5},
};

void map_check(t_game *g, char *map)
{
	g->map.size.x = 16;
	g->map.size.y = 8;
}

void	passing_type(t_game *g, char **split)
{
	if (ft_strcmp(split[0], "NO"))
		tex_init(g, 0, split[1]);
	else if (ft_strcmp(split[0], "SO"))
		tex_init(g, 1, split[1]);
	else if (ft_strcmp(split[0], "WE"))
		tex_init(g, 2, split[1]);
	else if (ft_strcmp(split[0], "EA"))
		tex_init(g, 3, split[1]);
	else if (ft_strcmp(split[0], "SO"))
		tex_init(g, 4, split[1]);
	else if (ft_strcmp(split[0], "S"))
		tex_init(g, 5, split[1]);
	else if (ft_strcmp(split[0], "F"))
		g->map.floor = RGB_check(split[1]);
	else if (ft_strcmp(split[0], "C"))
		g->map.ceiling = RGB_check(split[1]);
	else
		map_passing();
}

int main(int ac, char *av)
{
	t_game 		g;
	char	**line;
	int		i;
	if (ac < 2)
		printf("error\n");
	int fd = open(av[1], 1);
	i = 0;
	while (i < 8)
	{
		get_next_line(fd, &line);
		char **split;
		split = ft_split(line[i], ' ');
		if (file_component[i] == split[0])
			passing_type(&g, split);
		else
			break;
		i++;
	}
	g.pos.x = 6;
	g.pos.y = 4;
	g.dir.x = 1;
	g.dir.y = 0;
	g.plane = rotation(g.dir, M_PI / 2);
	
	window_init(&g);
	img_init(&g);
	mlx_hook(g.win, X_EVENT_KEY_PRESS, 0, &key_press, &g);
	mlx_hook(g.win, X_EVENT_KEY_RELEASE, 0, &key_release, &g);
	mlx_loop_hook(g.mlx, &main_loop, &g);
	mlx_loop(g.mlx);
	return (0);
}