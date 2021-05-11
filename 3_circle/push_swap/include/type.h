/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:57:52 by hopark            #+#    #+#             */
/*   Updated: 2021/05/11 15:40:26 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# define TYPE_H
# define ERROR  0
# define SUCESS 1
# define FALSE -1
# define NULLPTR 0
typedef int			t_bool;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE   1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX  10240
# endif

typedef struct s_list
{
	int				num;
	float			chunk;
	char			com;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

typedef struct s_inf
{
	struct s_list	*a_h;
	struct s_list	*a_t;
	struct s_list	*b_h;
	struct s_list	*b_t;
	char			bonus;
	int				max;
	int				min;
}				t_inf;

typedef struct s_pivot
{
	int				first;
	int				second;
}				t_pivot;

typedef struct s_color
{
	char			*yes;
	char			*no;
}				t_color;

#endif