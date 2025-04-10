/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:30:25 by psoulie           #+#    #+#             */
/*   Updated: 2025/04/10 11:44:27 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	printp(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->print);
	printf(str, get_new_time(philo), philo->id);
	pthread_mutex_unlock(philo->print);
}

void	routine(t_philo *philo)
{
	while (1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
}

void	run_philo(t_philo *philo)
{

}
