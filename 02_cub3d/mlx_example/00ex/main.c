#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define _USE_MATH_DEFINES

# define WIN_WIDTH 600
# define WIN_HEIGHT 400

# define IMG_WIDTH 600
# define IMG_HEIGHT 400

#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_RELEASE		3
#define X_EVENT_KEY_EXIT		17 //exit key code

#define KEY_ESC			53
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2



int minimap = 5;
int TILESIZE = 20;
int mapx = 16, mapy = 8;
float	FOV_ANGLE = 60 * (M_PI / 180);
int	WALL_STRIP_WIDTH = 1;
// int	NUM_RAYS = WIN_WIDTH / WALL_STRIP_WIDTH;
int	NUM_RAYS = 600;

int map[] = {
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,
	1,0,1,0,0,0,0,0,1,0,1,0,1,0,0,1,
	1,0,0,0,1,0,0,1,1,0,1,0,0,0,0,1,
	1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,
	1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};

typedef struct s_fvector
{
	float		x;
	float		y;
}				t_fvector;

typedef struct s_ivector
{
	int			x;
	int			y;
}				t_ivector;

typedef struct	s_img
{
	void		*img;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_fvector	pos;
	t_fvector	map_pos;
	t_fvector	map;
	t_fvector	dir;
	t_fvector	ray_dir;
	t_fvector	plane;
	t_fvector	turn;
	t_fvector	move;
	t_fvector	side;
	t_fvector	wall_h;
	t_fvector	wall_v;
	t_ivector	hit;

	float		angle;

}				t_game;


int		check_wall(t_game *game, t_fvector pt);

t_fvector		roation(t_fvector src, float angle)
{
	t_fvector dest;
	
	dest.x = cos(angle) * src.x - sin(angle) * src.y;
	dest.y = sin(angle) * src.x + cos(angle) * src.y;
	return (dest);
}

float	ft_max(float a, float b)
{
	return (a > b ? a : b);
}

float	ft_min(float a, float b)
{
	return (a < b ? a : b);
}
int				key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->move.x = 1;
	else if (keycode == KEY_S)
		game->move.y = 1;
	if (keycode == KEY_D)
		game->turn.x = 1;
	else if (keycode == KEY_A)
		game->turn.y = 1;
	return (0);
}

int				key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->move.x = 0;
	else if (keycode == KEY_S)
		game->move.y = 0;
	if (keycode == KEY_D)
		game->turn.x = 0;
	else if (keycode == KEY_A)
		game->turn.y = 0;
	return (0);
}



float		vector_len(t_fvector v1, t_fvector v2)
{
	float tempx;
	float tempy;

	if (v2.x == 0 && v2.y == 0)
	{
		tempx = sqrt(v1.x * v1.x + v2.y * v2.y);
		return (tempx);
	}
	tempx = fabs(v1.x - v2.x) * fabs(v1.x - v2.x);
	tempy = fabs(v1.y - v2.y) * fabs(v1.y - v2.y);
	tempx = sqrt(tempx + tempy);
	return (tempx);
}


void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "mlx 42");
}

void		map_check(t_game *game, char *map)
{
	game->map.x = 16;
	game->map.y = 8;
}

void	draw_line(t_game *game, t_fvector v1, t_fvector v2)
{
	float	dx;
	float	dy;
	float	step;

	dx = (v2.x - v1.x);
	dy = (v2.y - v1.y);
	step = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);
	dx /= step;
	dy /= step;
	while (fabs(v2.x - v1.x) > 1 || fabs(v2.y - v1.y) > 1)
	{
		game->img.data[(int)v1.y * IMG_WIDTH + (int)v1.x] = 0xFF00FF;
		v1.x += dx;
		v1.y += dy;
	}
}

void		draw_square(t_game *game, t_ivector pt, int size)
{
	int 	i;
	int 	j;

	i = 0;
	while(i < size)
	{
		j = 0;
		while(j < size)
		{
			game->img.data[(size * pt.y + i)*IMG_WIDTH  + size * pt.x + j] = 0x868e96;
			j++;
		}
	i++;
	}
}

int		check_wall(t_game *game, t_fvector pt)
{
	int		mapx;
	int		mpay;

	if (pt.x < 0 || pt.x > game->map.x || pt.y < 0 || pt.y > game->map.y)
		return (1);
	return (map[(int)(game->map_pos.y * game->map.x + game->map_pos.x)] != 0);
}

void		map_draw(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->map.y)
	{
		j = 0;
		while(j < game->map.x)
		{
			if(map[(i * (int)game->map.x + j)])
			{
				t_ivector pt = {j,i};
				draw_square(game, pt, TILESIZE);
			}
		j++;
		}
		i++;
	}
	i = 0;
	while (i <= game->map.y * TILESIZE)
	{
		j = 0;
		while (j <= game->map.x * TILESIZE)
		{
			if(i % TILESIZE == 0 || j % TILESIZE == 0)
				game->img.data[i *IMG_WIDTH + j] = 0xFFFFFF;
			j++;
		}
		i++;
	}
}

void		img_init(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, IMG_WIDTH, IMG_HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img.size_l, &game->img.endian);
	map_check(game, 0);
	map_draw(game);
}

int		update_image(t_game *game)
{
	float	camera;
	game->map.x = (int)game->pos.x;
	game->map.y = (int)game->pos.y;
	// for (int x = 0; x < NUM_RAYS; x++)
	// {
	// 	t_fvector	sideDist;
	// 	t_fvector	deltaDist;
	// 	t_ivector	step;

	// 	int			hit = 0;
	// 	int			side = 0;
	// 	float			perpWallDist;
	// 	camera = 2 * x / (float) NUM_RAYS - 1; 
	// 	game->ray_dir.x = game->dir.x + game->plane.x *camera;
	// 	game->ray_dir.y = game->dir.y + game->plane.y *camera;
	// 	if (game->ray_dir.x < 0)
	// 	{
	// 		step.x = -1;
	// 		sideDist.x = (game->pos.x - game->map_pos.x) * deltaDist.x;
	// 	}
	// 	else
	// 	{
	// 		step.x = 1;
	// 		sideDist.x - (game->map_pos.x + 1.0 - game->pos.x) * deltaDist.x;
	// 	}
	// 	if (game->ray_dir.y < 0)
	// 	{
	// 		step.y = -1;
	// 		sideDist.y = (game->pos.y - game->map_pos.y) * deltaDist.y;
	// 	}
	// 	else
	// 	{
	// 		step.y = 1;
	// 		sideDist.y - (game->map_pos.y + 1.0 - game->pos.y) * deltaDist.y;
	// 	}
	// 	while (hit == 0)
	// 	{
	// 		if (sideDist.x < sideDist.y)
	// 		{
	// 			sideDist.x += deltaDist.x;
	// 			game->map_pos.x += step.x;
	// 			side = 0;
	// 		}
	// 		else
	// 		{
	// 			sideDist.y += deltaDist.y;
	// 			game->map_pos.y += step.y;
	// 			side = 1;
	// 		}
	// 		if (map[game->map_pos.y * mapx + game->map_pos.x > 0])
	// 		{
	// 			hit = 1;
	// 		}
	// 	}
	// 	if (side == 0)
	// 		perpWallDist = (game->map_pos.x - game->pos.x + (1 - step.x) / 2) / game->ray_dir.x;
	// 	else
	// 		perpWallDist = (game->map_pos.y - game->pos.y + (1 - step.y) / 2) / game->ray_dir.y;
	// 	t_fvector v2 = {x, IMG_HEIGHT/2 - ft_min(IMG_HEIGHT / perpWallDist,IMG_HEIGHT/ 3)};
	// 	t_fvector v3 = {x, IMG_HEIGHT/2 + ft_min(IMG_HEIGHT / perpWallDist,IMG_HEIGHT/ 3)};
	// 	printf("x %d,x : %f|y :%f|pre %f|\n",x,game->map_pos.x, game->map_pos.y, perpWallDist);
	// 	draw_line(game, v2, v3);
	// }
	for(int i = -5; i <5; i++)
		for(int j = -5; j < 5; j++)
			game->img.data[((int)game->pos.y + i) * IMG_WIDTH + ((int)game->pos.x + j)] = 0xFF000F;
	draw_line(game, game->pos, game->pos);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return(0);
}



int		player_move(t_game *game)
{
	int		speed;
	speed = 2;
	if (game->move.x == 1)
	{
		t_fvector next_pt;
		next_pt.x = game->pos.x + game->dir.x;
		next_pt.y = game->pos.y + game->dir.y;

		if (!check_wall(game, next_pt))
			game->pos = next_pt;
	}
	else if (game->move.y == 1)
	{
		t_fvector next_pt;
		next_pt.x = game->pos.x - game->dir.x;
		next_pt.y = game->pos.y - game->dir.y;
		if (!check_wall(game, next_pt))
		{
			game->pos = next_pt;
			printf("dsafkljasdf\n");
		}
	}
	// printf("pos : x : %f y : %f\n", game->pos.x, game->pos.y);

	return(1);
}


int		player_turn(t_game *game)
{
	
	if (game->turn.x == 1)
		game->dir = roation(game->dir, M_PI/180);
	else if (game->turn.y == 1)
		game->dir = roation(game->dir, -M_PI/180);
	printf("dir : x : %f y : %f\n", game->dir.x, game->dir.y);
	return(1);
}

int		main_loop(t_game *game)
{
	img_init(game);

	static int update = 1;
	if (game->turn.x || game->turn.y)
		update = player_turn(game);
	if (game->move.x || game->move.y)
		update = player_move(game);
	if (update)
		update_image(game);
	update = 0;
	return (0);
}


int		main(void)
{
	t_game		game;
	game.pos.x = 2;
	game.pos.y = 2;
	game.dir.x = -1;
	game.dir.y = 0;	
	game.plane.x = 0;
	game.plane.y = 0.66;
	
	window_init(&game);
	img_init(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, &key_release, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
