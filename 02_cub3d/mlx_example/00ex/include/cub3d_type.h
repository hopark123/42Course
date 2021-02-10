/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_type.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 21:55:27 by hopark            #+#    #+#             */
/*   Updated: 2021/02/09 22:28:37 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_TYPE_H
# define CUB3D_TYPE_H

typedef struct s_sprite
{
	double x;
	double y;
	int num;
}				t_sprite;

typedef struct s_fvector
{
	float x;
	float y;
}				t_fvector;

typedef struct s_ivector
{
	int x;
	int y;
}				t_ivector;

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
}				t_ray;

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

typedef struct s_map
{
	t_ivector	size;
	float		floor;
	float		ceiling;
}				t_map;

typedef struct s_img
{
	void *ptr;
	int *data;
	int width;
	int height;
	int size_l;
	int bpp;
	int endian;
}				t_img;

typedef struct s_game
{
	void *mlx;
	void *win;
	t_img img;
	t_img tex[7];
	t_map map;
	t_fvector pos;
	t_fvector dir;
	t_ray ray;
	t_fvector plane;
	t_fvector turn;
	t_fvector move;

	float angle;

}				t_game;

#endif