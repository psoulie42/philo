/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:40:50 by psoulie           #+#    #+#             */
/*   Updated: 2025/04/10 16:04:10 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_death(t_philo *philo)
{
	pthread_mutex_lock((&philo->death));
	if (philo->is_dead)
		return (pthread_mutex_unlock((&philo->death)), 1);
	return (pthread_mutex_unlock((&philo->death)), 0);
}

void	philo_think(t_philo *philo)
{
	printp(philo, "is thinking");
}

void	philo_sleep(t_philo *philo)
{
	printp(philo, "is sleeping");
	usleep(philo->tsleep * 1000);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock((&philo->rfork));
	printp(philo, "has taken the fork to his right");
	pthread_mutex_lock(&(philo->lfork));
	printp(philo, "has taken the fork to his left");
	printp(philo, "is eating");
	usleep(philo->teat * 1000);
	pthread_mutex_unlock(&(philo->rfork));
	pthread_mutex_unlock(&(philo->lfork));
}
