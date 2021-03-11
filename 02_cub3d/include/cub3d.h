/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 22:06:31 by hopark            #+#    #+#             */
/*   Updated: 2021/03/09 13:38:35 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "cub3d.h"
# include "cub3d_type.h"
# include "get_next_line.h"
# include "utils.h"
# include "passing.h"
# include "../minilibx_opengl_20191021/mlx.h"

# define X_EVENT_KEY_PRESS		    2
# define X_EVENT_KEY_RELEASE		3
# define X_EVENT_KEY_EXI			17
# define KEY_ESC					53
# define KEY_Q						12
# define KEY_W						13
# define KEY_E						14
# define KEY_R						15
# define KEY_A						0
# define KEY_S						1
# define KEY_D						2
# define KEY_UP						126
# define KEY_DOWN					125
# define KEY_LEFT					123
# define KEY_RIGHT					124

int				ft_check_fwall(t_game *g, t_fvector pt);
int				ft_check_iwall(t_game *g, t_ivector pt);
void			ft_map_draw(t_game *g);
void			ft_draw_floor(t_game *g, unsigned int color);
void			ft_draw_ceiling(t_game *g, unsigned int color);
void			ft_draw_dir(t_game *g, unsigned int color);
void			ft_draw_pixel(t_game *g, t_fvector pt, unsigned int color);

void			ft_draw_line(t_game *g, t_fvector v1, t_fvector v2, int color);
void			ft_draw_square(t_game *g, t_ivector pt,\
								int size, unsigned int color);
void			ft_free(void *memory);
void			ft_free2(char **s, int i);
void			ft_exit_msg(t_game *g, char *msg);
void			ft_exit(t_game *g);
void			ft_tex_init(t_game *g, int num, char *path);
void			ft_window_init(t_game *g);
void			ft_img_init(t_game *g);
int				ft_key_press(int keycode, t_game *g);
int				ft_key_release(int keycode, t_game *g);
int				ft_update_image(t_game *g);
int				ft_main_loop(t_game *g);
int				ft_player_move(t_game *g);
int				ft_player_side(t_game *g);
int				ft_player_turn(t_game *g);
void			ft_ray_dda_init(t_game *g, t_ray *ray);
void			ft_ray_dda(t_game *g, t_ray *ray);
void			ft_ray_casting(t_game *g);
void			ft_ray_quadrant(t_ray *ray);
void			ft_ray_init(t_game *g, t_ray *ray, int i);
unsigned int	ft_choice_tex(t_game *g, t_draw draw, char dir);
void			ft_ray_draw(t_game *g, t_ray *ray, int i);
void			ft_sort_sprite(t_game *g);
void			ft_sprite_init(t_game *g, t_list *cur, t_sprites *spr);
void			ft_sprite_draw(t_game *g, t_sprites *spr);
int				ft_save_bmp(t_game *g);
int				ft_split_check(char **split, int num);

# ifndef TILESIZE
#  define TILESIZE 10
# endif

# ifndef FOV_ANGLE
#  define FOV_ANGLE 1.15192
# endif

# define BITMAPFILEHEADER 14
# define BITMAPINFOHEADER 40

float	g_zbuffer[800];

# define _USE_MATH_DEFINES

# define TEXTURE_SIZE 64
# define SPR_SIZE 64
# define SPR_WIDTH 64

#endif
