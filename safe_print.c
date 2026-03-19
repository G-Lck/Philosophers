# include "philo.h"

void	safe_print(t_philo *p, char *text)
{
	pthread_mutex_lock(p->info->print);
	if (!(p->info->someone_is_dead))
		printf(text,get_time() - p->info->start_time, p->num + 1);
	pthread_mutex_unlock(p->info->print);
}
