#include <unistd.h>
#include <stdlib.h>
#define error -1

typedef struct	s_list
{
	int				num;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;
typedef struct s_inf{
	t_list	*a_h;
	t_list	*a_t;
	t_list	*b_h;
	t_list	*b_t;
	t_list	*mid;
}				t_inf;

static int		ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int				ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int				ft_atoi(const char *nptr)
{
	int				num;
	int				sign;
	int				i;
	int				cnt;

	i = 0;
	sign = 1;
	num = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -1;
	cnt = i;
	while (ft_isdigit(nptr[i]))
	{
		num = num * 10 + nptr[i] - '0';
		i++;
	}
	if (nptr[i] != 0)
		return (-1);
	if (i - cnt >= 20)
		return (sign > 0 ? -1 : 0);
	return (num * sign);
}


int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i + 1 < n)
	{
		if (c1[i] != c2[i])
			break ;
		if (c1[i] * c2[i] == 0)
			break ;
		i++;
	}
	return (c1[i] - c2[i]);
}
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
int			main()
{

	t_list	*list1;
	t_list	*list2;
	t_list	*list3;
	t_list	*list4;
	t_list	*list5;
	t_list	*list6;
	t_list	*list7;
	t_list	*list8;
	t_list	*list9;
	t_list	*list0;


	int			i = 1;
	list1 = ft_listnew(1);
	list2 = ft_listnew(2);
	list3 = ft_listnew(3);
	list4 = ft_listnew(4);
	list5 = ft_listnew(5);

	list6 = ft_listnew(6);
	list7 = ft_listnew(7);
	list8 = ft_listnew(8);
	list9 = ft_listnew(9);
	list0 = ft_listnew(0);

	ft_listadd_back(&list3, &list4);
	ft_listadd_back(&list4, &list5);
	ft_listadd_front(&list3, &list2);

	ft_listadd_front(&list2, &list1);

	ft_listadd_back(&list6, &list7);
	ft_listadd_back(&list7, &list8);
	ft_listadd_back(&list8, &list9);
	ft_listadd_back(&list9, &list0);


	t_list *temp = list1;
	t_list *temp2 = list6;
	while (i < 7)
	{
		if (temp)
		{
			printf("now  : %d | ", temp->num);
		if (temp->prev)
			printf("prev : %d | ", temp->prev->num);
		else
			printf("prev : %d | ", 0);

		if (temp->next)
			{
				printf("next : %d | ", temp->next->num);
			}
		else
			printf("next : %d | ", 0);
		temp = temp->next;
		}
			printf("           ");
		if (temp2)
		{
		printf("now  : %d | ", temp2->num);
		if (temp2->prev)
			printf("prev : %d | ", temp2->prev->num);
		else
			printf("prev : %d | ", 0);

		if (temp2->next)
			{
				printf("next : %d | ", temp2->next->num);
			}
		else
			printf("next : %d | ", 0);
		temp2 = temp2->next;
		}
		printf("\n");
		i++;
	}
	printf("----------\n");
//void			ft_swap_tool(t_list **type)
//void			ft_push_tool(t_list **dest, t_list **src)

	//ft_listexcpet(&list2);
	//ft_swap_tool(&list2, &list3);
	ft_push_tool(&list2, &list7);
	temp = list1;
	temp2 = list6;
	i = 0;
	while (i < 7)
	{
		if (temp)
		{
			printf("now  : %d | ", temp->num);
		if (temp->prev)
			printf("prev : %d | ", temp->prev->num);
		else
			printf("prev : %d | ", 0);

		if (temp->next)
			{
				printf("next : %d | ", temp->next->num);
			}
		else
			printf("next : %d | ", 0);
		temp = temp->next;
		}
			printf("           ");
		if (temp2)
		{
		printf("now  : %d | ", temp2->num);
		if (temp2->prev)
			printf("prev : %d | ", temp2->prev->num);
		else
			printf("prev : %d | ", 0);

		if (temp2->next)
			{
				printf("next : %d | ", temp2->next->num);
			}
		else
			printf("next : %d | ", 0);
		temp2 = temp2->next;
		}
		printf("\n");
		i++;
	}

}