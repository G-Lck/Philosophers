# include "philo.h"

void	clean_info(t_info *info)
{
	free(info->forks);
	info->forks = NULL;
	free(info->print);
}

static void clean_philo(t_philo *philo)
{


	philo->left_fork = NULL;
	philo->right_fork = NULL;
	philo->info = NULL;
	return ;
}

int	clean_all_philos(t_info *info, t_philo *philos)
{
	int i;

	i = 0;
	while(i < info->n_of_philo)
	{
		clean_philo(&philos[i]);
		i++;
	}
	return (0);
}

void	clean(t_info *info, t_philo *philos)
{
	clean_all_philos(info, philos);
	clean_info(info);
	free(philos);
	philos = NULL;
	return ;
}
