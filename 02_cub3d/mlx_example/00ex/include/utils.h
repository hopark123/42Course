/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 22:14:31 by hopark            #+#    #+#             */
/*   Updated: 2021/02/09 22:28:27 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d_type.h"
#include "../..//mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float			ft_max(float a, float b);
float			ft_min(float a, float b);
static int		ft_count(char const *s, char c);
static int		ft_wordlen(char const *s, char c);
void			ft_iswap(int *a, int *b);
void			ft_fswap(float *a, float *b);
t_fvector		i_matrix_mulit(t_fvector m1, t_fvector m2, t_fvector v);
t_fvector		rotation(t_fvector src, float angle);
float			vector_len(t_fvector v1, t_fvector v2);


#endif