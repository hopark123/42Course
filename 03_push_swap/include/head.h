/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:06:13 by hopark            #+#    #+#             */
/*   Updated: 2021/04/28 19:36:45 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

typedef struct	s_list
{
	int				num;
	int				chunk;
	struct s_list	*prev;
	struct s_list	*next;

}				t_list;

typedef struct	s_inf
{
	struct s_list	*a_h;
	struct s_list	*a_t;
	struct s_list	*b_h;
	struct s_list	*b_t;
}				t_inf;


/////////////////////////////////////








///////////////////////////////////

void			ft_action(t_inf *inf, char *com);
int				ft_swap_tool(t_list **type);
int				ft_push_tool(t_list **dest, t_list **src);
int				ft_rotate_tool(t_inf *inf, char *com);
int				ft_r_rotate_tool(t_inf *inf, char *com);

void			ft_make_list(int ac, char **av, t_inf *inf);

void			ft_three_a(t_inf *inf);
void			ft_three_b(t_inf *inf);


int				ft_is_ascending(t_list *list);
int				ft_is_descending(t_list *list);
int				ft_chunk_is_descending(t_list *list);

///////////////////////////////////ft_list
t_list			*ft_n_next(t_list *list, int n);
t_list			*ft_listnew(int num);
void			ft_listadd_front(t_list **list, t_list **new);
void			ft_listadd_back(t_list **list, t_list **new);
void			ft_listdelone(t_list **list);
void			ft_listexcpet(t_list **list);
void			ft_listclear(t_list **list);


#endif