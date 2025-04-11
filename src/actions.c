/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:40:50 by psoulie           #+#    #+#             */
/*   Updated: 2025/04/11 15:13:35 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_think(t_philo *philo)
{
	printp(philo, "is thinking");
	ft_sleep(1, philo);
}

void	philo_sleep(t_philo *philo)
{
	printp(philo, "is sleeping");
	ft_sleep(philo->tsleep, philo);
}

void	philo_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
		philo_eat_odd(philo);
	else
		philo_eat_even(philo);
}

void	philo_eat_even(t_philo *philo)
{
	pthread_mutex_lock((&philo->rfork));
	printp(philo, "has taken the fork to his right");
	pthread_mutex_lock(philo->lfork);
	printp(philo, "has taken the fork to his left");
	philo->last_meal = get_new_time(philo->start_time) + philo->teat;
	ft_sleep(philo->teat, philo);
	printf("%lo %i teat: %i\n", get_new_time(philo->start_time), philo->id, philo->teat);
	pthread_mutex_unlock(&(philo->rfork));
	pthread_mutex_unlock(philo->lfork);
}

void	philo_eat_odd(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	printp(philo, "has taken the fork to his left");
	pthread_mutex_lock((&philo->rfork));
	printp(philo, "has taken the fork to his right");
	philo->last_meal = get_new_time(philo->start_time) + philo->teat;
	printp(philo, "is eating");
	ft_sleep(philo->teat, philo);
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(&(philo->rfork));
}
