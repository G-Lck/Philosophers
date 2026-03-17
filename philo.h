#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdint.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct s_info
{
	int				n_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_of_eat;
	int				someone_is_dead;
	uint64_t		start_time;
	pthread_mutex_t	*print;
	pthread_mutex_t	*forks;
} t_info;

typedef struct s_philo
{
	int				num;
	pthread_t		id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_info			*info;
} t_philo;

//number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

uint64_t get_time(void);
int	ft_usleep(useconds_t time);

int		ft_strlen(char *str);
int		ft_atoi(char *str);
int		is_all_digit(char *str);

void	*routine(void *philo);

int		init_forks(t_info *info);
int		init_all_philos(t_info *info, t_philo *philos);

# endif
