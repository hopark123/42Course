/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:17:20 by hopark            #+#    #+#             */
/*   Updated: 2020/11/28 23:15:18 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TYPE_H
# define FT_PRINTF_TYPE_H

typedef struct		s_flag
{
	char		left;
	char		plus;
	char		blank;
	char		zero;
	char		hash;
}					t_flag;

typedef struct		s_infor
{
	t_flag	flag;
	int		len;
	int		width;
	int		precision;
	int		size;
	char	nega;
	char	type;
	char	*content;
	int		hcount;
	int		lcount;
}					t_infor;

#endif
