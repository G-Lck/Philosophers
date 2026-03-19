/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 21:39:21 by glucken           #+#    #+#             */
/*   Updated: 2026/03/19 21:39:21 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *p)
{
	int	n;

	pthread_mutex_lock(&p->info->dying);
	n = p->info->should_stop;
	pthread_mutex_unlock(&p->info->dying);
	return (n);
}

static void	sleeping(t_philo *p)
{
	if (check_death(p))
		return ;
	safe_print(p, "%lli %i is sleeping\n");
	ft_usleep(p->info->time_to_sleep);
}

static void	thinking(t_philo *p)
{
	if (check_death(p))
		return ;
	safe_print(p, "%lli %i is thinking\n");
	if (p->info->n_of_philo % 2 == 1)
		ft_usleep(p->info->time_to_eat);
}

void	*routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *) philo;
	if (p->num % 2 == 1)
		ft_usleep(p->info->time_to_eat / 2);
	while (1)
	{
		if (check_death(p))
			return (NULL);
		eat(p);
		sleeping(p);
		thinking(p);
	}
	return (NULL);
}
