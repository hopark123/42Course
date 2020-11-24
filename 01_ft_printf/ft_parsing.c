/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:19:57 by hopark            #+#    #+#             */
/*   Updated: 2020/11/25 01:47:32 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			ft_parsing(char **format, va_list ap, t_infor *infor)
{
	int			cnt;
	char		*ptr;

	while (**format)
	{
		if (ft_strchr("-+ 0#", **format))
		{
			ft_check_flag(format, infor);
		}
		else if (ft_strchr("123456789*", **format))
			ft_check_width(format, infor, ap);
		else if (ft_strchr(".", **format))
			ft_check_precision(format, infor, ap);
		else
		{
			infor->type = **format;
			ft_make_content(infor, ap);
			(*format)++;
			ft_putstr_fd((infor->content), 1);
			return (ft_strlen(infor->content));
		}
	}
	return (0);
}
