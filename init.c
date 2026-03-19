/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 22:09:24 by glucken           #+#    #+#             */
/*   Updated: 2026/03/19 22:09:24 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	init_info(int argc, char *argv[], t_info *info)
{
	info->n_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->should_stop = 0;
	pthread_mutex_init(&info->print, NULL);
	pthread_mutex_init(&info->dying, NULL);
	init_forks(info);
	if (argc == 6)
		info->n_of_eat = ft_atoi(argv[5]);
	else
		info->n_of_eat = -1;
	info->start_time = get_time();
}

static void	init_philo(t_philo *philo, t_info *info, int num)
{
	philo->num = num;
	philo->left_fork = &info->forks[num % info->n_of_philo];
	philo->right_fork = &info->forks[(num + 1) % info->n_of_philo];
	philo->info = info;
	philo->last_meal = info->start_time;
	philo->n_meal = 0;
	return ;
}

void	init_all_philos(t_info *info, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < info->n_of_philo)
	{
		init_philo(&philos[i], info, i);
		i++;
	}
}
