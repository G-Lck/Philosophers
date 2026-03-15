# include "philo.h"

void	*routine(void *philo)
{
	t_philo *p;

	p = (t_philo *) philo;

	if (p->num % 2 == 0)
	{
		pthread_mutex_lock(p->left_fork);
		pthread_mutex_lock(p->right_fork);
		pthread_mutex_lock(p->info->print);
		printf("philo %i is eating \n", p->num);
		pthread_mutex_unlock(p->info->print);
		ft_usleep(p->info->time_to_eat);
		pthread_mutex_unlock(p->right_fork);
		pthread_mutex_unlock(p->left_fork);
	}else
	{
		pthread_mutex_lock(p->right_fork);
		pthread_mutex_lock(p->left_fork);
		pthread_mutex_lock(p->info->print);
		printf("philo %i is eating \n", p->num);
		pthread_mutex_unlock(p->info->print);
		ft_usleep(p->info->time_to_eat);
		pthread_mutex_unlock(p->left_fork);
		pthread_mutex_unlock(p->right_fork);
	}

	return (NULL);
}
