/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:35:56 by hopark            #+#    #+#             */
/*   Updated: 2021/04/15 16:49:40 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int				get_number(char *s)
{
	return (1);
}


void			ft_swap_tool(t_list **type)
{
	int			temp;

	if (*type == 0 || (*type)->next == 0)
		return ;
	temp = (*type)->num;
	(*type)->num = (*type)->next->num;
	(*type)->next->num = temp;
}

void			ft_swap(t_inf *inf, char *com)
{
	if (ft_strncmp(com, "sa", 2) || ft_strncmp(com, "ss", 2)) 
		ft_swap_tool(&(inf->a_h));
	if (ft_strncmp(com, "sb", 2) || ft_strncmp(com, "ss", 2))
		ft_swap_tool(&(inf->b_h));
}

void			ft_push_tool(t_list **dest, t_list **src)
{
	t_list		**temp;

	if ((*src) == 0)
		return ;
	temp = src;
	ft_listexcpet(src);
	(*src) = (*src)->next;
	ft_listadd_back(dest, temp);
}

void			ft_push(t_inf *inf, char *com)
{
	if (ft_strncmp(com, "pa", 2)) 
		ft_push_tool(&(inf->a_h), &(inf->a_h));
	if (ft_strncmp(com, "pb", 2) )
		ft_push_tool(&(inf->b_h) , &(inf->a_h));
}

void			ft_rotate(t_inf *inf, char *com)
{
	if (ft_strncmp(com, "ra", 2) || ft_strncmp(com, "rr", 2)) 
		(inf->a_h) = inf->a_h->next;
	if (ft_strncmp(com, "rb", 2) || ft_strncmp(com, "rr", 2))
		(inf->b_h) = inf->b_h->next;
}

void			ft_r_rotate(t_inf *inf, char *com)
{
	if (ft_strncmp(com, "rra", 3) || ft_strncmp(com, "rrr", 3)) 
		(inf->a_h) = inf->a_h->prev;
	if (ft_strncmp(com, "rrb", 3) || ft_strncmp(com, "rrr", 3))
		(inf->b_h) = inf->b_h->prev;
}
void			make_list(int ac, char **av, t_inf *inf)
{
	t_list		*old;
	t_list		*new;
	int			i;
	int			num;
	
	old = 0;
	inf->a_h = old;
	i = 0;
	while (av[++i])
	{
		num = ft_atoi(av[++i]);
		new = ft_listnew(num);
		ft_listadd_back(&old, &new);
		old = new;
		inf->b_h = new;
	}
	inf->b_h->next = inf->a_h;
	inf->a_h->prev = inf->b_h;
}

int			main(int ac, char **av)
{
	static t_inf *inf;
	
	if (!(inf = malloc(sizeof(t_inf))))
		return (error);
	make_list(ac, av, inf);
	get_next_line()
}