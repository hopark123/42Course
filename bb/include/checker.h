/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:57:27 by hopark            #+#    #+#             */
/*   Updated: 2021/05/11 15:21:57 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "type.h"
# include "utils.h"
# include "engine.h"
int		ft_action_c(t_inf *inf, char *com);
int		ft_swap_tool(t_list **type);
int		ft_push_tool(t_list **dest, t_list **src);
int		ft_rotate_tool(t_list **head, t_list **tail);
int		ft_revrotate_tool(t_list **head, t_list **tail);
void	ft_checker(t_inf *inf);

#endif