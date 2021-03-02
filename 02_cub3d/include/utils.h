/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 22:14:31 by hopark            #+#    #+#             */
/*   Updated: 2021/02/27 15:30:15 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d_type.h"
# include "cub3d.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int					ft_atoi(const char *nptr);
float				ft_max(float a, float b);
float				ft_min(float a, float b);
char				**ft_split(char const *s, char c);
void				ft_iswap(int *a, int *b);
void				ft_fswap(float *a, float *b);
t_fvector			ft_i_matrix_multi(t_fvector m1, t_fvector m2, t_fvector v);
t_fvector			ft_rotation(t_fvector src, float angle);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst);
void				ft_lstclear(t_list **lst);
int					ft_memcmp(const void *s1, const void *s2, int n);
void				*ft_memset(void *s, int c, int n);
float				ft_vector_len(t_fvector v1, t_fvector v2);

#endif