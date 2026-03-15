# include "philo.h"

int	is_valid(int argc, char* argv[], t_info	*info)
{
	int i;

	if (!(argc == 5 || argc == 6))
		return (0);
	i = 1;
	while(i < argc)
	{
		if (!is_all_digit(argv[i]))
			return (0);
		i++;
	}
	info->n_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->n_of_eat = ft_atoi(argv[5]);
	return (1);
}

int	main(int argc, char* argv[])
{
	int i;
	t_info info;
	t_philo *philos;

	if (!is_valid(argc, argv, &info))
		return(printf("I think you are doing shit\n"), 1);


	printf("begin\n");
	philos = malloc((sizeof(t_philo) * info.n_of_philo));
	init_forks(&info);
	info.print = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(info.print, NULL);
	init_all_philos(&info, philos);

	i = 0;
	while (i < info.n_of_philo)
	{
		pthread_create(&philos[i].id, NULL, routine, &philos[i]);
		i++;
	}

	i = 0;
	while (i < info.n_of_philo)
	{
		pthread_join(philos[i].id, NULL);
		i++;
	}
	return (0);

}

//number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
