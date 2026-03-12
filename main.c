# include "philo.h"

void *start_routine1(void *arg)
{
	struct s_fork *fork1;
	int i;
	fork1 = (struct s_fork *)arg;

	i = 0;
	pthread_mutex_lock(fork1->lock);
	while (i++ < 100000)
		(*fork1->object) +=1;
	pthread_mutex_unlock(fork1->lock);
	return (NULL);
}

void *start_routine2(void *arg)
{
	struct s_fork *fork1;
	int i;
	fork1 = (struct s_fork *)arg;

	i = 0;
	pthread_mutex_lock(fork1->lock);
	while (i++ < 100000)
		(*fork1->object) -=1;
	pthread_mutex_unlock(fork1->lock);
	return (NULL);
}

int	main(int argc, char* argv[])
{
	pthread_t thread1;
	pthread_t thread2;
	int n; 
	struct s_fork	fork1;
	pthread_mutex_t lock1;


	n = 0;

	if (argc != 1)
		return(printf("I think you are doing shit\n"), 1);


	pthread_mutex_init(&lock1, NULL);
	fork1.object=&n;
	fork1.lock=&lock1;
	pthread_create(&thread1, NULL, start_routine1, &fork1);
	pthread_create(&thread2, NULL, start_routine2, &fork1);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("n is %i\n", n);
	return (0);
	
}

//number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]