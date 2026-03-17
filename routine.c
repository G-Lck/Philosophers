# include "philo.h"

void	eat(t_philo *p, uint64_t *last_meal)
{
	if (p->num % 2 == 0)
	{
		pthread_mutex_lock(p->right_fork);
		pthread_mutex_lock(p->left_fork);
		pthread_mutex_lock(p->info->print);
		if (!p->info->someone_is_dead)
			printf("philo %i is eating \n", p->num);
		pthread_mutex_unlock(p->info->print);
		//printf("%li philo %i is eating \n", get_time() - p->info->start_time, p->num);
		ft_usleep(p->info->time_to_eat);
		*last_meal = get_time();
		ft_usleep(p->info->time_to_eat);
		pthread_mutex_unlock(p->left_fork);
		pthread_mutex_unlock(p->right_fork);

	}else
	{
		pthread_mutex_lock(p->left_fork);
		pthread_mutex_lock(p->right_fork);
		pthread_mutex_lock(p->info->print);
		if (!p->info->someone_is_dead)
			printf("philo %i is eating \n", p->num);
		ft_usleep(p->info->time_to_eat);
		*last_meal = get_time();
		pthread_mutex_unlock(p->info->print);
		ft_usleep(p->info->time_to_eat);
		pthread_mutex_unlock(p->right_fork);
		pthread_mutex_unlock(p->left_fork);
	}
}

void	sleeping(t_philo *p)
{
	pthread_mutex_lock(p->info->print);
	if (!p->info->someone_is_dead)
		printf("philo %i is sleeping \n", p->num);
	ft_usleep(p->info->time_to_sleep);
	pthread_mutex_unlock(p->info->print);
}

int	is_dead(t_philo *p, uint64_t *last_meal)
{
	if (get_time() - *last_meal > (uint64_t)(p->info->time_to_die))
	{
		pthread_mutex_lock(p->info->print);
		printf("philo %i is dead \n", p->num);
		pthread_mutex_unlock(p->info->print);
		p->info->someone_is_dead = 1;
		return (1);
	}
	else
	{
		*last_meal = get_time();
		return (0);
	}
}

void	thinking(t_philo *p)
{
	pthread_mutex_lock(p->info->print);
	printf("philo %i is thinking \n", p->num);
	pthread_mutex_unlock(p->info->print);
}

void	*routine(void *philo)
{
	t_philo *p;
	uint64_t last_meal;
	int i;

	i = 0;

	last_meal = get_time();

	p = (t_philo *) philo;

	while (i++ < 3)
	{
		printf("hello\n");
		if (p->info->someone_is_dead || is_dead(p, &last_meal))
			break;
		printf("hello2\n");
		eat(p, &last_meal);
		if (p->info->someone_is_dead)
			break;
		printf("hello3\n");
		sleeping(p);
		if (p->info->someone_is_dead)
			break;
		thinking(p);
	}

	return (NULL);
}
