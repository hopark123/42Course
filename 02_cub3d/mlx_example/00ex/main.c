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
int TILESIZE = 32;
int mapx = 8, mapy = 8;
int map[] = {
	1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,1,0,0,1,
	1,0,1,1,1,1,0,1,
	1,0,0,0,1,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,
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
	t_fvector	position;
	t_fvector	dirction;
	t_fvector	turn;
	t_fvector	move;
	t_fvector	side;
	t_ivector	map;
	t_fvector	wall_h;
	t_fvector	wall_v;
	t_ivector	hit;
	float		angle;

}				t_game;


int		check_wall(t_game *game, t_fvector pt);

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



// float		vecotr_len(t_fvector v1, t_fvector v2)
// {
// 	float tempx;
// 	float tempy;

// 	if (v2.x == 0 && v2.y == 0)
// 	{
// 		tempx = sqrt(v1.x * v1.x + v2.y * v2.y);
// 		return (tempx);
// 	}
// 	tempx = abs(v1.x - v2.x) * abs(v1.x - v2.x);
// 	tempy = abs(v1.y - v2.y) * abs(v1.x - v2.x);
// 	tempx = sqrt(tempx + tempy);
// 	return (tempx);
// }


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

void	darw_line(t_game *game, t_fvector pt1, t_fvector pt2)
{
	// float y_step = (pt2.y - pt1.y) / (pt2.x - pt1.x);
	// for(int i = 0; i < abs(pt2.x-pt1.x); i++)
	// 	game->img.data[(int)(pt1.y + i) * IMG_WIDTH + (int)(pt1.x + i)] = 0xFFFF00;
	float angle = (pt2.y-pt1.y) / (pt2.x - pt1.x);
	for(int i = 0; i < 50; i++)
		{
			game->img.data[(int)(pt1.y + i*cos(angle)) * IMG_WIDTH + (int)(pt1.x + i*sin(angle))] = 0xFFFF00;
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

void	hit_horztal(t_game *game)
{
	int		face_up;
	int		face_right;
	t_fvector		intercept;
	t_fvector		step;
	t_fvector		next;

	face_up = 1;
	if (game->angle > 0 && game->angle < M_PI)
		face_up = -1;
	face_right = -1;
	if (game->angle < 0.5 * M_PI || game->angle > 1.5 * M_PI)
		face_right = 1;
	intercept.y = floor(game->position.y / TILESIZE) * TILESIZE;
	intercept.y += (face_up == 1) ? 0 : TILESIZE;
	intercept.x = game->position.x + (intercept.y - game->position.y) / tan(game->angle);

	step.y = TILESIZE;
	step.y *= (face_up  == 1) ? -1 : 1;

	step.x = TILESIZE / tan(game->angle);
	step.x *= (face_right == -1 && step.x > 0) ? -1 : 1;
	step.x *= (face_right == 1 && step.x < 0) ? -1 : 1;

	next.y = (face_up == 1) ? intercept.y - 1 : intercept.y;
	next.x = intercept.x;
	// printf("angle : %f   tan : %f\n", game->angle, tan(game->angle));
	// printf("angle : %f right : %d up  :%d \n",  game->angle, face_right, face_up);
	// printf("step x : %f y : %f\n\n", step.x, step.y);

	while (next.x >= 0 && next.x <= WIN_WIDTH && next.y >= 0 && next.y <= WIN_HEIGHT)
		if (!check_wall(game, next))
		{
			game->hit.y = 1;
			game->wall_h.y = next.y;
			game->wall_h.x = next.x;
			// printf("wall_h x : %f y : %f\n",game->wall_h.x, game->wall_h.y);
			game->img.data[(int)(game->wall_h.y) * IMG_WIDTH + (int)(game->wall_h.x)] = 0xFF000F;

			// darw_line(game, game->position, game->wall_h);
			break;
		}
		else{
			next.y += step.y;
			next.x += step.x;
		}
}

void	hit_vertical(t_game *game)
{
	int		face_up;
	int		face_right;
	t_fvector		intercept;
	t_fvector		step;
	t_fvector		next;

	face_up = 1;
	if (game->angle > 0 && game->angle < M_PI)
		face_up = -1;
	face_right = -1;
	if (game->angle < 0.5 * M_PI || game->angle > 1.5 * M_PI)
		face_right = 1;
	intercept.y = floor(game->position.y / TILESIZE) * TILESIZE;
	intercept.y += (face_up == 1) ? 0 : TILESIZE;
	intercept.x = game->position.x + (intercept.y - game->position.y) / tan(game->angle);

	step.y = TILESIZE;
	step.y *= (face_up  == 1) ? -1 : 1;

	step.x = TILESIZE / tan(game->angle);
	step.x *= (face_right == -1 && step.x > 0) ? -1 : 1;
	step.x *= (face_right == 1 && step.x < 0) ? -1 : 1;

	next.y = (face_up == 1) ? intercept.y - 1 : intercept.y;
	next.x = intercept.x;
	// printf("angle : %f   tan : %f\n", game->angle, tan(game->angle));
	// printf("angle : %f right : %d up  :%d \n",  game->angle, face_right, face_up);
	// printf("step x : %f y : %f\n\n", step.x, step.y);

	while (next.x >= 0 && next.x <= WIN_WIDTH && next.y >= 0 && next.y <= WIN_HEIGHT)
		if (!check_wall(game, next))
		{
			game->hit.x = 1;
			game->wall_v.y = next.y;
			game->wall_v.x = next.x;
			// printf("wall_v x : %f y : %f\n",game->wall_v.x, game->wall_v.y);
			game->img.data[(int)(game->wall_v.y) * IMG_WIDTH + (int)(game->wall_v.x)] = 0xFF000F;

			// darw_line(game, game->position, game->wall_v);
			break;
		}
		else{
			next.y += step.y;
			next.x += step.x;
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
	for(int j = 0; j < 1; j++)
	{
		for(int i = 0; i < 50; i++)
		{
			game->img.data[(int)(game->position.y + i*sin(game->angle + 0.01 * j)) * IMG_WIDTH + (int)(game->position.x + i*cos(game->angle + 0.01 *j))] = 0xFF0F00 + j;
		}
	}
	hit_horztal(game);
	for(int i = -5; i <5; i++)
		for(int j = -5; j < 5; j++)
			game->img.data[((int)game->position.y + i) * IMG_WIDTH + ((int)game->position.x + j)] = 0xFF00FF;
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	// printf("x : %f y : %f\n",  game->position.x, game->position.y);
	// printf("dx : %f dy : %f\n",  game->dirction.x, game->dirction.y);
	// printf("angle : %f\n",  game->angle);

	return(0);
}

int		check_wall(t_game *game, t_fvector pt)
{
	int		mapx;
	int		mpay;

	if (pt.x < 0 || pt.x > game->map.x * TILESIZE || pt.y < 0 || pt.y > game->map.y * TILESIZE)
		return (0);
	mapx = (int)floor(pt.x / TILESIZE);
	mapy = (int)floor(pt.y / TILESIZE);
	return (map[mapy * game->map.x + mapx] == 0);
}

int		player_move(t_game *game)
{
	if (game->move.x == 1)
	{
		t_fvector next_pt;
		next_pt.x = game->position.x + game->dirction.x;
		next_pt.y = game->position.y + game->dirction.y;
		if (check_wall(game, next_pt))
			game->position = next_pt;
	}
	else if (game->move.y == 1)
	{
		t_fvector next_pt;
		next_pt.x = game->position.x - game->dirction.x;
		next_pt.y = game->position.y - game->dirction.y;
		if (check_wall(game, next_pt))
			game->position = next_pt;
	}
	return(1);
}

int		player_turn(t_game *game)
{
	int		speed;
	speed = 2;
	if (game->turn.x == 1)
		game->angle += M_PI/180;
	else if (game->turn.y == 1)
		game->angle -= M_PI/180;
	if (game->angle < 0)
		game->angle += 2*M_PI;
	if (game->angle > 2*M_PI)
		game->angle -= 2*M_PI;
	game->dirction.x = speed * cos(game->angle);
	game->dirction.y = speed * sin(game->angle);
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
	game.position.x = 100;
	game.position.y = 150;
	game.angle = 0;
	
	window_init(&game);
	img_init(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, &key_release, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
