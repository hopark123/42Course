#include "../mlx/mlx.h"
#include <stdio.h>
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


#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_RELEASE 3
#define X_EVENT_KEY_EXIT 17 //exit key code
#define KEY_ESC 53
#define KEY_Q 12
#define KEY_W 13
#define KEY_E 14
#define KEY_R 15
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

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
typedef struct s_sprite
{
	double x;
	double y;
	int num;
}		t_sprite;
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

typedef struct s_fvector
{
	float x;
	float y;
} t_fvector;

typedef struct s_ivector
{
	int x;
	int y;
} t_ivector;

typedef struct s_img
{
	void *ptr;
	int *data;
	int width;
	int height;
	int size_l;
	int bpp;
	int endian;
} t_img;

typedef struct s_ray
{
	float		x;
	float		y;
	float		q;
	float		cam;
	t_fvector	side;
	t_fvector	delta;
	t_ivector	step;
	t_ivector	map_pos;
	int			check;
	float		dis;
	float		len;
	char		dir;
	float		point;
}			t_ray;
typedef struct s_draw
{
	t_fvector	put;
	t_fvector	tex;
	t_fvector	start;
	t_fvector	end;
	t_fvector	step;
	t_fvector	pixel;
	unsigned int	color;
}				t_draw;
typedef struct s_sprites
{
	t_fvector	temp;
	t_fvector	trans;
	t_fvector	sprite;
	float		screenX;
	int			num;
	int			*order;
}				t_sprites;

typedef struct s_game
{
	void *mlx;
	void *win;
	t_img img;
	t_img tex[7];
	t_fvector pos;
	t_ivector map_size;
	t_fvector dir;
	t_ray ray;
	t_fvector plane;
	t_fvector turn;
	t_fvector move;

	float angle;

} t_game;

int check_fwall(t_game *game, t_fvector pt);

t_fvector roation(t_fvector src, float angle)
{
	t_fvector dest;

	dest.x = cos(angle) * src.x - sin(angle) * src.y;
	dest.y = sin(angle) * src.x + cos(angle) * src.y;
	return (dest);
}

float ft_max(float a, float b)
{
	return (a > b ? a : b);
}

float ft_min(float a, float b)
{
	return (a < b ? a : b);
}

t_fvector i_matrix_mulit(t_fvector m1, t_fvector m2, t_fvector v)
{
	t_fvector 	res;
	float		invert;

	invert = 1.0 / (m1.x * m2.y - m1.y * m2.x);
	res.x = invert * (m2.y * v.x - m2.x * v.y);
	res.y = invert * (-m1.y * v.x + m1.x * v.y);
	return(res);
}

int key_press(int keycode, t_game *game)
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

int key_release(int keycode, t_game *game)
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

float vector_len(t_fvector v1, t_fvector v2)
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

void window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "mlx 42");
}

void map_check(t_game *game, char *map)
{
	game->map_size.x = 16;
	game->map_size.y = 8;
}

void draw_pixel(t_game *game, t_fvector pt, unsigned int color)
{
	game->img.data[(int)pt.y * IMG_WIDTH + (int)pt.x] = color;
}

void draw_line(t_game *game, t_fvector v1, t_fvector v2, int color)
{
	float dx;
	float dy;
	float step;

	dx = (v2.x - v1.x);
	dy = (v2.y - v1.y);
	step = ft_max(fabs(dx), fabs(dy));
	dx /= step;
	dy /= step;
	while (fabs(v2.x - v1.x) > 1 || fabs(v2.y - v1.y) > 1)
	{
		game->img.data[(int)v1.y * IMG_WIDTH + (int)v1.x] = color;
		v1.x += dx;
		v1.y += dy;
	}
}

void draw_square(t_game *game, t_ivector pt, int size, unsigned int color)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			game->img.data[(size * pt.y + i) * IMG_WIDTH + size * pt.x + j] = color;
			j++;
		}
		i++;
	}
}

int check_fwall(t_game *game, t_fvector pt)
{
	if (pt.x < 0 || pt.x > game->map_size.x || pt.y < 0 || pt.y > game->map_size.y)
		return (1);
	return (map[(int)pt.y * game->map_size.x + (int)pt.x] != 0);
}

int check_iwall(t_game *game, t_ivector pt)
{
	if (pt.x < 0 || pt.x > game->map_size.x || pt.y < 0 || pt.y > game->map_size.y)
		return (1);
	return (map[pt.y * game->map_size.x + pt.x] != 0);
}

void map_draw(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->map_size.y)
	{
		j = 0;
		while (j < game->map_size.x)
		{
			t_ivector pt;

			pt.x = j;
			pt.y = i;
			if (map[(i * (int)game->map_size.x + j)])
				draw_square(game, pt, TILESIZE, 0x868e96);
			else
				draw_square(game, pt, TILESIZE, 0x000000);
			j++;
		}
		i++;
	}
	i = 0;
	while (i <= game->map_size.y * TILESIZE)
	{
		j = 0;
		while (j <= game->map_size.x * TILESIZE)
		{
			if (i % TILESIZE == 0 || j % TILESIZE == 0)
				game->img.data[i * IMG_WIDTH + j] = 0xFFFFFF;
			j++;
		}
		i++;
	}
}


void	ft_iswap(int *a, int *b)
{
	int		temp;
	temp = *a;
	*a = *b;
	*b = temp; 
}

void	ft_fswap(float *a, float *b)
{
	float		temp;
	temp = *a;
	*a = *b;
	*b = temp; 
}

void	tex_init(t_game *game, int num, char *path)
{
	game->tex[num].ptr = mlx_xpm_file_to_image(game->mlx, path, &game->tex[num].width, &game->tex[num].height);
	game->tex[num].data = (int *)mlx_get_data_addr(game->tex[num].ptr, &game->tex[num].bpp, &game->tex[num].size_l, &game->tex[num].endian);
}

unsigned int	choice_tex(t_game *game, t_draw draw, char dir)
{
	unsigned int color;
	int			tex_num;
	if (dir == 'E')
		tex_num = 0;
	else if (dir == 'W')
		tex_num = 1;
	else if (dir == 'S')
		tex_num = 2;
	else if (dir == 'N')
		tex_num = 3;
	color = game->tex[tex_num].data[(int)(draw.tex.y * TEXTURE_SIZE) * TEXTURE_SIZE + (int)draw.tex.x];
	return (color);
}

void img_init(t_game *game)
{
	int		i;
	game->img.ptr = mlx_new_image(game->mlx, IMG_WIDTH, IMG_HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.ptr, &game->img.bpp, &game->img.size_l, &game->img.endian);
	i = 0;
	tex_init(game, 0, "img/wall_e.xpm");
	tex_init(game, 1, "img/wall_w.xpm");
	tex_init(game, 2, "img/wall_s.xpm");
	tex_init(game, 3, "img/wall_n.xpm");
	tex_init(game, 4, "img/bird.xpm");
	tex_init(game, 5, "img/tree.xpm");


				for (int i = 0; i < IMG_WIDTH; i++)
					for (int j = 0; j < IMG_HEIGHT /2 ; j++)
					{
						t_fvector v = {i, j};
						draw_pixel(game, v, 0XFFBBFF);
					}
				for (int i = 0; i < IMG_WIDTH; i++)
					for (int j = IMG_HEIGHT/2; j < IMG_HEIGHT ; j++)
					{
						t_fvector v = {i, j};
						draw_pixel(game, v, 0XFFAA00);
					}
	map_check(game, 0);
}

void ray_quadrant(t_ray *ray)
{
	if (ray->x >= 0 && ray->y < 0)
		ray->q = 1;
	else if (ray->x < 0 && ray->y < 0)
		ray->q = 2;
	else if (ray->x < 0 && ray->y >= 0)
		ray->q = 3;
	else if (ray->x >= 0 && ray->y >= 0)
		ray->q = 4;
}

void ray_init(t_game *game, t_ray *ray, int i)
{
	ray->check = 0;
	ray->map_pos.x = (int)game->pos.x;
	ray->map_pos.y = (int)game->pos.y;

	ray->cam = 2 * i / (float)NUM_RAYS - 1;
	ray->x = game->dir.x + game->plane.x * ray->cam;
	ray->y = game->dir.y + game->plane.y * ray->cam;
	ray_quadrant(ray);
	ray->delta.x = fabs(1 / ray->x);
	ray->delta.y = fabs(1 / ray->y);
}

void ray_dda_init(t_game *game, t_ray *ray)
{
	if (ray->q == 2 || ray->q == 3)
	{
		ray->step.x = -1;
		ray->side.x = (game->pos.x - ray->map_pos.x) * ray->delta.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side.x = (ray->map_pos.x + 1.0 - game->pos.x) * ray->delta.x;
	}
	if (ray->q == 1 || ray->q == 2)
	{
		ray->step.y = -1;
		ray->side.y = (game->pos.y - ray->map_pos.y) * ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side.y = (ray->map_pos.y + 1.0 - game->pos.y) * ray->delta.y;
	}
}

void ray_dda(t_game *game, t_ray *ray)
{
	while (ray->check == 0)
	{
		if (ray->side.x < ray->side.y)
		{
			ray->side.x += ray->delta.x;
			ray->map_pos.x += ray->step.x;
			if (ray->q == 2 || ray->q == 3)
				ray->dir = 'W';
			else
				ray->dir = 'E';
		}
		else
		{
			ray->side.y += ray->delta.y;
			ray->map_pos.y += ray->step.y;
			if (ray->q == 1 || ray->q == 2)
				ray->dir = 'N';
			else
				ray->dir = 'S';
		}
		if (check_iwall(game, ray->map_pos))
			ray->check = 1;
	}
	if (ray->dir == 'W' || ray->dir == 'E')
	{
		ray->dis = (ray->map_pos.x - game->pos.x + (1 - ray->step.x) / 2) / ray->x;
		ray->point = game->pos.y + ray->dis * ray->y;
	}
	else
	{
		ray->dis = (ray->map_pos.y - game->pos.y + (1 - ray->step.y) / 2) / ray->y;
		ray->point = game->pos.x + ray->dis * ray->x;
	}
}

void ray_draw(t_game *game, t_ray *ray, int i)
{
	t_draw		draw;

	ray->len = IMG_WIDTH / 3 / ray->dis / tan(FOV_ANGLE / 2);
	draw.pixel.y = ray->len > IMG_HEIGHT ? (ray->len - IMG_HEIGHT) / 2: 0;
	// draw.step.y = (ray->len > IMG_HEIGHT) ? (ray->len -  IMG_HEIGHT) / ray->len : 1;
	draw.start.y = ft_max((IMG_HEIGHT - ray->len) / 2, 0);
	draw.end.y = ft_min((IMG_HEIGHT + ray->len) / 2, IMG_HEIGHT - 1);
	draw.start.x = i;
	while (draw.start.y < draw.end.y)
	{
		draw.tex.x = (ray->point - floor(ray->point)) * TEXTURE_SIZE;
		if (ray->dir == 'W' || ray->dir == 'S')
			draw.tex.x = TEXTURE_SIZE - draw.tex.x - 1;
		draw.tex.y = draw.pixel.y / ray->len;
		draw.color = choice_tex(game, draw, ray->dir);
		draw_pixel(game, draw.start, draw.color);
		draw.start.y++;
		draw.pixel.y++;
	}
}

int		*sort_sprite(t_game *game, t_sprite *sprite)
{
	float	distance[numSprites];
	int		*order;
	int i;
	int	j;

	if (!(order = malloc(sizeof(int) * (numSprites + 1))))
		return (0);
	i = 0;
	while (i < numSprites)
	{
		distance[i] = sqrt((game->pos.x - sprite[i].x) * (game->pos.x - sprite[i].x) + (game->pos.y - sprite[i].y) * (game->pos.y- sprite[i].y)); 
		order[i] = i;
		i++;
	}
	i = 0;
	while (i < numSprites)
	{
		j = i;
		while (j < numSprites)
		{

			if (distance[i] < distance[j])
			{
				ft_fswap(&distance[i], &distance[j]);
				ft_iswap(&order[i], &order[j]);
			}
			j++;
		}
		i++;
	}
	i = 0;
	return (order);
}

void	sprite_init (t_game *game, t_sprites *spr, int	order)
{
	spr->temp.x = sprite[order].x - game->pos.x;
	spr->temp.y = sprite[order].y - game->pos.y;
	spr->num = sprite[order].num;
	spr->trans = i_matrix_mulit(game->plane, game->dir, spr->temp);
	spr->screenX = (WIN_WIDTH/2) * (1 + spr->trans.x / spr->trans.y);
	spr->sprite.y = fabs((IMG_HEIGHT / spr->trans.y));
	spr->sprite.x = fabs((IMG_WIDTH / spr->trans.y));
}

void		sprite_draw(t_game *game, t_sprites *spr)
{
	t_draw draw;
	draw.start.x = ft_max(spr->screenX - spr->sprite.x / 2 , 0);
	draw.end.x =  ft_min(spr->screenX + spr->sprite.x / 2, IMG_WIDTH - 1) ;
	while (draw.start.x < draw.end.x)
	{
		draw.start.y = ft_max((IMG_HEIGHT- spr->sprite.y) / 2, 0);
		draw.end.y = ft_min((IMG_HEIGHT + spr->sprite.y)/ 2, IMG_HEIGHT - 1);
		draw.pixel.x = (int)(256 * (draw.start.x - (spr->screenX - spr->sprite.x / 2)) * SPRITE_SIZE / spr->sprite.x  / 256);
		if (spr->trans.y > 0 && spr->trans.y < ZBUFFER[(int)draw.start.x])
			while (draw.start.y < draw.end.y)
			{
				draw.step.y = draw.start.y * 256 - IMG_HEIGHT * 128 + spr->sprite.y * 128;
				draw.pixel.y = (int)(draw.step.y * SPRITE_SIZE / spr->sprite.y / 256);
				draw.color = game->tex[spr->num].data[(int)(draw.pixel.y * SPRITE_SIZE) + (int)draw.pixel.x];
				if ((draw.color & 0x00FFFFFF) != 0)
					draw_pixel(game, draw.start, draw.color);
				draw.start.y++;
			}
		draw.start.x++;
	}
}

void ray_casting(t_game *game)
{
	int 	i;
	int		*order;
	i = 0;
	while (i < NUM_RAYS)
	{
		t_ray ray;
		ray_init(game, &ray, i);
		ray_dda_init(game, &ray);
		ray_dda(game, &ray);
		ray_draw(game, &ray, i);
		ZBUFFER[i] = ray.dis;
		i++;
	}
		i = 0;
	order = sort_sprite(game, sprite);
	while (i < numSprites)
	{	
		t_sprites	spr;

		sprite_init(game, &spr, order[i]);
		sprite_draw(game, &spr);
		
		i++;
	}
}

int update_image(t_game *game)
{
	ray_casting(game);
	map_draw(game);

				//player, line
				for (int i = -5; i < 5; i++)
					for (int j = -5; j < 5; j++)
						game->img.data[((int)((game->pos.y * TILESIZE + i)) * IMG_WIDTH + (int)(game->pos.x * TILESIZE + j))] = 0xFF000F;
				t_fvector v1 = {TILESIZE * game->pos.x + TILESIZE * game->dir.x, TILESIZE * game->pos.y + TILESIZE * game->dir.y};
				t_fvector v2 = {TILESIZE * game->pos.x, TILESIZE * game->pos.y};
				draw_line(game, v1, v2, 0xFF00FF);
	mlx_put_image_to_window(game->mlx, game->win, game->img.ptr, 0, 0);
	mlx_do_sync(game->mlx);
	return (0);
}

int player_move(t_game *game)
{
	float speed;

	speed = 0.1;
	if (game->move.x == 1)
	{
		t_fvector next_pt;
		next_pt.x = game->pos.x + speed * game->dir.x;
		next_pt.y = game->pos.y + speed * game->dir.y;

		if (!check_fwall(game, next_pt))
			game->pos = next_pt;
	}
	else if (game->move.y == 1)
	{
		t_fvector next_pt;
		next_pt.x = game->pos.x - speed * game->dir.x;
		next_pt.y = game->pos.y - speed * game->dir.y;
		if (!check_fwall(game, next_pt))
		{
			game->pos = next_pt;
		}
	}
	return (1);
}

int player_turn(t_game *game)
{
	if (game->turn.x == 1)
		game->dir = roation(game->dir, M_PI / 60);
	else if (game->turn.y == 1)
		game->dir = roation(game->dir, -M_PI / 60);
	game->plane = roation(game->dir, M_PI / 2);
	return (1);
}

int main_loop(t_game *game)
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

int main(void)
{
	t_game game;
	game.pos.x = 6;
	game.pos.y = 4;
	game.dir.x = 1;
	game.dir.y = 0;
	game.plane = roation(game.dir, M_PI / 2);
	
	window_init(&game);
	img_init(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, &key_release, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}