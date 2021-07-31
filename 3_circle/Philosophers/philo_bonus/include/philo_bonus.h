#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include "util.h"
# define SUCCESS	1
# define ERROR		0
# define INT_MAX	2147483647
typedef struct s_info
{
	int				num;
	long			time_start;
	long			time_die;
	long			time_eat;
	long			time_sleep;
	int				must_eat;
	int				*pids;
	sem_t			*sem;
	sem_t			*alive;
	sem_t			*print_s;
	int				kill;
	pthread_t		tid;
	struct s_philo	**philo;
}			t_info;

typedef struct s_philo
{
	int				index;
	int				full;
	int				check;
	int				fork;
	int				cnt_eat;
	long			last_eat;
	pthread_t		tid;
	struct s_info	*info;
}			t_philo;

int		init_info(t_info *info, int ac, char **av);
long	ft_get_time(void);
int		ft_strncmp(const char *s1, const char *s2, int n);
void	test_int(char *type, int num);
void	*ft_try_fork(void *arg);
void	ft_drop_fork(t_info *info, t_philo *philo);
void	*ft_game(t_philo *philo);
void	ft_printf(t_info *info, long time, int index, char *str);
int		ft_check_death(t_info *info, t_philo *philo);
t_philo	*ft_init_philo(t_info *info, int i);
void	*ft_kill_all(void *arg);
void	ft_philo_bonus(t_info *info);
void	ft_free_philo(t_info *info);

#endif