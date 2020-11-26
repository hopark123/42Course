/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:17:20 by hopark            #+#    #+#             */
/*   Updated: 2020/11/26 18:44:28 by hopark           ###   ########.fr       */
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
	int		nega;
	int		len;
	int		width;
	int		precision;
	int		size;
	char	type;
	char	*content;
}					t_infor;

#endif
