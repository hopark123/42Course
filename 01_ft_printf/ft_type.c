/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:17:20 by hopark            #+#    #+#             */
/*   Updated: 2020/11/25 03:16:21 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
