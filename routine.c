# include "philo.h"

void	eat(t_philo *p, uint64_t *last_meal)
{
	if (p->num % 2 == 0)
	{
		pthread_mutex_lock(p->right_fork);
		pthread_mutex_lock(p->left_fork);
		safe_print(p, "%lli %i is eating\n");
		//printf("%li philo %i is eating \n", get_time() - p->info->start_time, p->num);
		*last_meal = get_time();
		ft_usleep(p->info->time_to_eat);
		pthread_mutex_unlock(p->left_fork);
		pthread_mutex_unlock(p->right_fork);

	}else
	{
		pthread_mutex_lock(p->left_fork);
		safe_print(p, "%lli %i has taken a fork\n");
		pthread_mutex_lock(p->right_fork);
		safe_print(p, "%lli %i has taken a fork\n");
		safe_print(p, "%lli %i is eating\n");
		*last_meal = get_time();
		ft_usleep(p->info->time_to_eat);
		pthread_mutex_unlock(p->right_fork);
		pthread_mutex_unlock(p->left_fork);
	}
}

void	sleeping(t_philo *p)
{
	safe_print(p, "%lli %i is sleeping\n");
	ft_usleep(p->info->time_to_sleep);
}

void	thinking(t_philo *p)
{
	safe_print(p, "%lli %i is thinking\n");
}

int	is_dead(t_philo *p, uint64_t *last_meal)
{
	if (get_time() - *last_meal > (uint64_t)(p->info->time_to_die))
	{
		pthread_mutex_lock(p->info->print);
		printf("%li %i died \n", get_time() - p->info->start_time, p->num + 1);
		p->info->someone_is_dead = 1;
		pthread_mutex_unlock(p->info->print);
		return (1);
	}
	else
	{
		return (0);
	}
}

int	should_continue_to_eat(t_philo *p, int i)
{
	if (p->info->n_of_eat == -1)
		return (1);
	else
		return (i < p->info->n_of_eat);
}

void	*routine(void *philo)
{
	t_philo *p;
	uint64_t last_meal;
	int i;

	i = 0;

	p = (t_philo *) philo;
	last_meal = get_time();

	while (should_continue_to_eat(p, i))
	{
		if (p->info->someone_is_dead || is_dead(p, &last_meal))
			break;
		eat(p, &last_meal);
		if (p->info->someone_is_dead)
			break;
		sleeping(p);
		if (p->info->someone_is_dead)
			break;
		thinking(p);
		i++;
	}

	return (NULL);
}
