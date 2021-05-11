/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:57:37 by hopark            #+#    #+#             */
/*   Updated: 2021/05/11 15:11:21 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H
# include "type.h"
# include "utils.h"
void	ft_exit(t_inf *inf, char *msg, int fd);
void	ft_htsetting(t_inf *inf);
void	ft_inf_init(t_inf *inf);
int		ft_is_ascending(t_list *list);
int		ft_is_descending(t_list *list);
int		ft_chunk_is_descending(t_list *list);
int		ft_isnew(t_inf *inf, int num);
int		ft_make_list(char **av, t_inf *inf);
int		ft_make_list2(t_inf *inf, char **av, int i);
int		ft_make_split(char **av, t_inf *inf);
int		ft_make_split2(t_inf *inf, char **split);
#endif