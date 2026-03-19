/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 22:26:20 by glucken           #+#    #+#             */
/*   Updated: 2026/03/19 22:57:36 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_valid(int argc, char *argv[])
{
	int	i;

	if (!(argc == 5 || argc == 6))
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!is_all_digit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	create_philos(t_info *info, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < info->n_of_philo)
	{
		pthread_create(&philos[i].id, NULL, routine, &philos[i]);
		i++;
	}
	pthread_create(&info->monkey, NULL, observation, philos);
}

static void	wait_philos(t_info *info, t_philo *philos)
{
	int	i;

	pthread_join(info->monkey, NULL);
	i = 0;
	while (i < info->n_of_philo)
	{
		pthread_join(philos[i].id, NULL);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_info	info;
	t_philo	*philos;

	if (!is_valid(argc, argv))
		return (printf("The programme takes the following"
				" arguments: number_of_philosophers time_to_die"
				" time_to_eat time_to_sleep"
				" [number_of_times_each_philosopher_must_eat]\n"), 1);
	init_info(argc, argv, &info);
	philos = malloc(sizeof(t_philo) * info.n_of_philo);
	if (!philos)
		return (1);
	init_all_philos(&info, philos);
	create_philos(&info, philos);
	wait_philos(&info, philos);
	clean(&info, philos);
	return (0);
}
