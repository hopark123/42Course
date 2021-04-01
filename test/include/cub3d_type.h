/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_type.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 21:55:27 by hopark            #+#    #+#             */
/*   Updated: 2021/03/09 11:10:49 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_TYPE_H
# define CUB3D_TYPE_H

typedef struct	s_fvector
{
	float x;
	float y;
}				t_fvector;

typedef struct	s_ivector
{
	int x;
	int y;
}				t_ivector;

typedef struct	s_list
{
	char				*content;
	t_fvector			pt;
	float				dis;
	struct s_list		*next;
}				t_list;

typedef struct	s_ray
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

typedef struct	s_draw
{
	t_fvector		put;
	t_fvector		tex;
	t_fvector		start;
	t_fvector		end;
	t_fvector		step;
	t_fvector		pixel;
	unsigned int	color;
}				t_draw;

typedef struct	s_sprites
{
	t_fvector	temp;
	t_fvector	trans;
	t_fvector	sprite;
	float		scx;
	int			*order;
}				t_sprites;

typedef struct	s_map
{
	t_ivector	size;
	float		floor;
	float		ceiling;
	char		**m;
	char		*no;
	char		*ea;
	char		*so;
	char		*we;
	char		*s;
	int			flag;
	int			cnt_sprite;
}				t_map;

typedef struct	s_img
{
	void		*ptr;
	int			*data;
	int			width;
	int			height;
	int			size_l;
	int			bpp;
	int			endian;
	int			line;
}				t_img;

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_img		tex[5];
	t_map		map;
	t_fvector	pos;
	t_fvector	dir;
	t_fvector	plane;
	t_fvector	turn;
	t_fvector	move;
	t_fvector	side;
	int			inpos;
	t_list		*spr;

}				t_game;

#endif
