/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 21:44:47 by glucken           #+#    #+#             */
/*   Updated: 2026/03/19 21:44:47 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat_even(t_philo *p)
{
	pthread_mutex_lock(p->right_fork);
	safe_print(p, "%lli %i has taken a fork\n");
	pthread_mutex_lock(p->left_fork);
	p->last_meal = get_time();
	safe_print(p, "%lli %i has taken a fork\n");
	safe_print(p, "%lli %i is eating\n");
	p->last_meal = get_time();
	ft_msleep(p->info->time_to_eat);
	p->n_meal++;
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->right_fork);
}

static void	eat_odd(t_philo *p)
{
	pthread_mutex_lock(p->left_fork);
	safe_print(p, "%lli %i has taken a fork\n");
	pthread_mutex_lock(p->right_fork);
	p->last_meal = get_time();
	safe_print(p, "%lli %i has taken a fork\n");
	safe_print(p, "%lli %i is eating\n");
	p->last_meal = get_time();
	ft_msleep(p->info->time_to_eat);
	p->n_meal++;
	pthread_mutex_unlock(p->right_fork);
	pthread_mutex_unlock(p->left_fork);
}

void	eat(t_philo *p)
{
	if (p->info->n_of_philo == 1)
	{
		pthread_mutex_lock(p->left_fork);
		safe_print(p, "%lli %i has taken a fork\n");
		ft_msleep(p->info->time_to_die + 1);
		pthread_mutex_unlock(p->left_fork);
		return ;
	}
	if (check_death(p))
		return ;
	if (p->num % 2 == 0)
		eat_even(p);
	else
		eat_odd(p);
}
