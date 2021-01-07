#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define _USE_MATH_DEFINES

# define WIN_WIDTH 1200
# define WIN_HEIGHT 960

# define IMG_WIDTH 1200
# define IMG_HEIGHT 960

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
int mapx = 8, mapy = 8;
int map[] = {
	1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,1,0,0,1,
	1,0,0,0,1,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,
};

typedef struct s_vector
{
	int		x;
	int		y;
}				t_vector;

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
	t_vector	position;
	float		angle;
	t_vector	dirction;
	t_vector	turn;
	t_vector	move;
	t_vector	side;
	t_vector	wall;
	t_vector	map;
}				t_game;



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



float		vecotr_len(t_vector v1, t_vector v2)
{
	float tempx;
	float tempy;

	if (v2.x == 0 && v2.y == 0)
	{
		tempx = sqrt(v1.x * v1.x + v2.y * v2.y);
		return (tempx);
	}
	tempx = abs(v1.x - v2.x) * abs(v1.x - v2.x);
	tempy = abs(v1.y - v2.y) * abs(v1.x - v2.x);
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
	game->map.x = 8;
	game->map.y = 8;
}

void		draw_square(t_game *game, t_vector pt, t_vector size)
{
	int 	i;
	int 	j;

	i = 0;
	while(i < size.y)
	{
		j = 0;
		while(j < size.x)
		{
			game->img.data[(size.y * pt.y + i)*IMG_WIDTH  + size.x * pt.x + j] = 0x868e96;
			j++;
		}
	i++;
	}
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
				t_vector pt = {j,i};
				t_vector pt2 = {IMG_WIDTH/minimap/game->map.x, IMG_HEIGHT/minimap/game->map.y};
				draw_square(game, pt, pt2);
			}
		j++;
		}
		i++;
	}

	for(i = 0; i <= IMG_HEIGHT/minimap; i++)
	{
		for(j = 0; j <= IMG_WIDTH/minimap; j++)
		{
			if(i % ((int)IMG_HEIGHT/minimap/game->map.y) == 0 || j % ((int)IMG_WIDTH/minimap/game->map.x) == 0)
				game->img.data[i *IMG_WIDTH + j] = 0xFFFFFF;
		}
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
	for(int j = -100; j < 100; j++)
	{
		for(int i = 0; i < 5000; i++)
		{
			if (map[(int)(game->position.y + i*cos(game->angle + 0.01 * j)) / 100 * mapy + (int)(game->position.x + i*sin(game->angle + 0.01 *j)) / 100] == 1)
			{
				game->wall.x = i*cos(game->angle + 0.01 * j);
				game->wall.y = i*sin(game->angle + 0.01 * j);

				t_vector zero = {0,0};
				int len = (int)(100 / (vecotr_len(game->wall, zero)) + cos(j/200 *M_PI) + 20);

				// printf("%d\n", len);
				for(int k = 0; k < len; k++)
					for(int m = 0; m < 1; m++)
						game->img.data[IMG_WIDTH + k*WIN_WIDTH + m + j + 200] = 0xFF0F00 + j;

				break;
			}
			game->img.data[(int)(game->position.y + i*cos(game->angle + 0.01 * j)) * IMG_WIDTH + (int)(game->position.x + i*sin(game->angle + 0.01 *j))] = 0xFF0F00 + j;
		}
	}
	for(int i = -5; i <5; i++)
		for(int j = -5; j < 5; j++)
			game->img.data[((int)game->position.y + i) * IMG_WIDTH + ((int)game->position.x + j)] = 0xFF00FF;
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	// printf("x : %f y : %f\n",  game->position.x, game->position.y);
	// printf("dx : %f dy : %f\n",  game->dirction.x, game->dirction.y);
	return(0);
}

int		check_wall_x(t_game *game, int a)
{
	int 	x;
	int 	y;
	int		dx;
	int		dy;
	int		flag;

	flag = 1;
	x = (int)(game->position.x / 100);
	y = (int)(game->position.y / 100);
	dx = game->dirction.x * a > 0 ? 1 : -1;
	dy = game->dirction.y *a > 0 ? 1 : -1;

	if (dx < 0 && map[y * mapy + x + dx] == 1 && (int)game->position.x % 100 < 5)
		flag = 0;
	if (dx > 0 && map[y * mapy + x + dx] == 1 && (int)game->position.x % 100 > 95)
		flag = 0;
	if (dy < 0 && map[(y + dy) * mapy + x] == 1 && (int)game->position.y % 100 < 5)
		flag = 0;
	if (dy > 0 && map[(y + dy) * mapy + x] == 1 && (int)game->position.y % 100 > 95)
		flag = 0;
	return (flag);
}

int		check_wall_y(t_game *game, int a)
{
	int 	x;
	int 	y;
	int		dx;
	int		dy;
	int		flag;

	flag = 1;
	x = (int)(game->position.x / 100);
	y = (int)(game->position.y / 100);
	dx = game->dirction.x * a > 0 ? 1 : -1;
	dy = game->dirction.y * a> 0 ? 1 : -1;

	if (dy < 0 && map[(y + dy) * mapy + x] == 1 && (int)game->position.y % 100 < 5)
		flag = 0;
	if (dy > 0 && map[(y + dy) * mapy + x] == 1 && (int)game->position.y % 100 > 95)
		flag = 0;
	return (flag);
}

int		player_move(t_game *game)
{
	if (game->move.x == 1)
	{
		if (game->position.x + game->dirction.x + 5.1 < IMG_WIDTH  && game->position.x + game->dirction.x > 5.1 && check_wall_x(game, 1))
			game->position.x += game->dirction.x;
		if (game->position.y + game->dirction.y + 5.1 < IMG_HEIGHT && game->position.y + game->dirction.y > 5.1 && check_wall_y(game, 1))
			game->position.y += game->dirction.y;
	}
	else if (game->move.y == 1)
	{
		if (game->position.x - game->dirction.x + 5.1 < IMG_WIDTH  && game->position.x - game->dirction.x > 5.1 && check_wall_x(game, -1))
			game->position.x -= game->dirction.x;
		if (game->position.y - game->dirction.y + 5.1 < IMG_HEIGHT && game->position.y - game->dirction.y > 5.1 && check_wall_y(game, -1))
			game->position.y -= game->dirction.y;
	}
	return(1);
}

int		player_turn(t_game *game)
{
	if (game->turn.x == 1)
		game->angle -= 0.05;
	else if (game->turn.y == 1)
		game->angle += 0.05;
	if (game->angle < 0)
		game->angle += 2*M_PI;
	if (game->angle > 2*M_PI)
		game->angle -= 2*M_PI;
	game->dirction.x = (int)(5 * sin(game->angle));
	game->dirction.y = (int)(5 * cos(game->angle));
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
	game.position.x = 200;
	game.position.y = 250;
	game.angle = M_PI;
	window_init(&game);
	img_init(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, &key_release, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
