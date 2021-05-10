/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:57:46 by hopark            #+#    #+#             */
/*   Updated: 2021/05/10 16:00:25 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "type.h"
# include "utils.h"
# include "engine.h"
int		g_cnt;
void	ft_action(t_inf *inf, char *com);
int		ft_swap_tool(t_list **type);
int		ft_push_tool(t_list **dest, t_list **src);
int		ft_rotate_tool(t_list **head, t_list **tail);
int		ft_revrotate_tool(t_list **head, t_list **tail);
int		ft_cnt_chunk(t_list *list);
t_pivot	ft_find_pivot(t_list *list);
int		ft_bonus_check(char **av, t_inf *inf);
void	ft_show_head(t_inf *inf, char *com);
void	ft_show_a(t_inf *inf, int *flag1, t_list **tempa, t_color color);
void	ft_show_b(t_inf *inf, int *flag2, t_list **tempb, t_color color);
void	ft_color_init(t_inf *inf, t_color *color);
void	ft_show(t_inf *inf, char *com);
void	ft_more_a(t_inf *inf, t_pivot pivot, int cnt_chunk, float chunk);
void	ft_more_a2(t_inf *inf);
void	ft_sort_a(t_inf *inf, float chunk);
void	ft_sort_a2(t_inf *inf, float chunk);
void	ft_more_b(t_inf *inf, t_pivot pivot, int cnt_chunk, float chunk);
void	ft_sort_b(t_inf *inf, float chunk);
void	ft_back_a(t_inf *inf, float chunk);
int		ft_sorted_already(t_inf *inf);
void	ft_sorted_excpet(t_inf *inf);
void	ft_three_a1(t_inf *inf);
void	ft_three_a2(t_inf *inf);
void	ft_three_a3(t_inf *inf);
void	ft_three_a(t_inf *inf, float chunk);
void	ft_n_pa(t_inf *inf, int n);
void	ft_three_b2(t_inf *inf);
void	ft_three_b3(t_inf *inf);
void	ft_three_b(t_inf *inf, float chunk);
void	ft_two_a(t_inf *inf, float chunk);
void	ft_two_b(t_inf *inf, float chunk);

#endif