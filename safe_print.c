/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 22:06:48 by glucken           #+#    #+#             */
/*   Updated: 2026/03/19 22:06:48 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	safe_print(t_philo *p, char *text)
{
	uint64_t	time;

	if (check_death(p))
		return ;
	time = get_time() - p->info->start_time;
	pthread_mutex_lock(&p->info->print);
	printf(text, time, p->num + 1);
	pthread_mutex_unlock(&p->info->print);
}
