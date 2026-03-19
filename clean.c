/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 21:35:49 by glucken           #+#    #+#             */
/*   Updated: 2026/03/19 21:35:49 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_info(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_of_philo)
	{
		pthread_mutex_destroy(&info->forks[i]);
		i++;
	}
	free(info->forks);
	info->forks = NULL;
	pthread_mutex_destroy(&info->print);
	pthread_mutex_destroy(&info->dying);
}

static void	clean_philo(t_philo *philo)
{
	philo->left_fork = NULL;
	philo->right_fork = NULL;
	philo->info = NULL;
	return ;
}

static int	clean_all_philos(t_info *info, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < info->n_of_philo)
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
