#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include "util.h"
# define SUCCESS	1
# define ERROR		0

typedef struct s_philo	t_philo;

typedef struct s_info
{
	int				num;
	long			time_start;
	long			time_die;
	long			time_eat;
	long			time_sleep;
	int				must_eat;
	int				alive;
	pthread_t		*tid;
	t_philo			**philo;
	pthread_mutex_t	**fork_m;
	int				*fork;
	pthread_mutex_t	*print_m;
}				t_info;

typedef struct s_philo
{
	int			index;
	long		last_eat;
	int			cnt_eat;
	int			alive;
	int			full;
	pthread_t	tid;
	t_info		*info;
}				t_philo;

typedef int			t_bool;


long	ft_atoi(const char *nptr);
int	ft_strlen(const char *s);
int	ft_strncmp(const char *s1, const char *s2, int n);
char	*ft_strndup(const char *s, int len);
void	*ft_memcpy(void *dst, const void *src, int n);
char	*ft_strchr(const char *s, char c);
int	ft_putchar_fd(char c, int fd, char *color);
int	ft_putstr_fd(char *s, int fd, char *color);
int	ft_putnbr_fd(int n, int fd, char *color);
t_bool	ft_malloc(void *target, int size);
long	ft_get_time(void);
void	ft_free(void *memory);





void	*ft_game(void *arg);
void	*ft_check_death(void *arg);
void	ft_printf(t_info *info, long time, int index, char *str);



void	test_str(char *type, char *str);
void	test_str2(char *type, char **str);
void	test_int(char *type, int num);
void	test_spot(char	*str);

#endif