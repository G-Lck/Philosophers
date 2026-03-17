# include "philo.h"

int	init_forks(t_info *info)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = malloc(sizeof(pthread_mutex_t) * info->n_of_philo);
	if (!forks)
		return (1);
	i = 0;

	while (i < info->n_of_philo)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	info->forks = forks;
	return (0);
}

static void init_philo(t_philo *philo, t_info *info, int num)
{

	philo->num = num;
	philo->left_fork = &info->forks[num % info->n_of_philo];
	philo->right_fork = &info->forks[(num + 1) % info->n_of_philo];
	philo->info = info;
	return ;
}

int	init_all_philos(t_info *info, t_philo *philos)
{
	int i;

	i = 0;
	while(i < info->n_of_philo)
	{
		init_philo(&philos[i], info, i + 1);
		i++;
	}
	return (0);
}
