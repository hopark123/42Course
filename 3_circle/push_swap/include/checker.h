/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:06:13 by hopark            #+#    #+#             */
/*   Updated: 2021/05/09 17:26:18 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHCEKR_H
# define CHCEKR_H
# include "type.h"
# include "utils.h"
# include "engine.h"
int	ft_action_c(t_inf *inf, char *com);
int	ft_swap_tool(t_list **type);
int	ft_push_tool(t_list **dest, t_list **src);
int	ft_rotate_tool(t_list **head, t_list **tail);
int	ft_revrotate_tool(t_list **head, t_list **tail);
void	ft_checker(t_inf *inf);


#endif