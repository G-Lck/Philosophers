#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>

struct s_fork
{
	int				*object;
	pthread_mutex_t *lock;
};

#endif