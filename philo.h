/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 22:07:56 by glucken           #+#    #+#             */
/*   Updated: 2026/03/19 22:41:14 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdint.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct s_info
{
	int				n_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_of_eat;
	int				should_stop;
	uint64_t		start_time;
	pthread_t		monkey;
	pthread_mutex_t	dying;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
}	t_info;

typedef struct s_philo
{
	int				num;
	pthread_t		id;
	uint64_t		last_meal;
	int				n_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_info			*info;
}	t_philo;

void		safe_print(t_philo *p, char *text);

uint64_t	get_time(void);
int			ft_usleep(useconds_t time);

int			ft_strlen(char *str);
int			ft_atoi(char *str);
int			is_all_digit(char *str);

void		eat(t_philo *p);
int			check_death(t_philo *p);
void		*routine(void *philo);
void		*observation(void *philos);

void		init_info(int argc, char *argv[], t_info *info);
void		init_all_philos(t_info *info, t_philo *philos);

void		clean(t_info *info, t_philo *philos);
void		clean_info(t_info *info);

#endif
