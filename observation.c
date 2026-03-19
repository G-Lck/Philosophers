/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 21:51:38 by glucken           #+#    #+#             */
/*   Updated: 2026/03/19 21:51:38 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	not_all_eat(t_philo	*p)
{
	int	i;
	int	max_meal;

	i = 0;
	max_meal = p->info->n_of_eat;
	while (i < p->info->n_of_philo)
	{
		if (p[i].n_meal < max_meal)
			return (1);
		i++;
	}
	return (0);
}

static int	continue_to_eat(t_philo *p)
{
	if (p->info->n_of_eat == -1)
		return (1);
	else if (not_all_eat(p))
		return (1);
	else
		return (0);
}

static int	someone_is_dead(t_philo *p)
{
	int	i;

	i = 0;
	while (i < p[0].info->n_of_philo)
	{
		if (get_time() - p[i].last_meal > (uint64_t)p[i].info->time_to_die)
		{
			pthread_mutex_lock(&p[0].info->dying);
			p[i].info->should_stop = 1;
			pthread_mutex_unlock(&p[0].info->dying);
			pthread_mutex_lock(&p[0].info->print);
			printf("%li %d died\n", get_time() - p[0].info->start_time,
				p[i].num + 1);
			pthread_mutex_unlock(&p[0].info->print);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*observation(void *philos)
{
	t_philo	*p;

	p = (t_philo *) philos;
	while (1)
	{
		if (!continue_to_eat(p))
		{
			pthread_mutex_lock(&p[0].info->dying);
			p[0].info->should_stop = 1;
			pthread_mutex_unlock(&p[0].info->dying);
			return (NULL);
		}
		if (someone_is_dead(p))
			return (NULL);
		usleep(100);
	}
	return (NULL);
}
