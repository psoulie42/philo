/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:40:50 by psoulie           #+#    #+#             */
/*   Updated: 2025/04/10 11:44:10 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->rfork);
	printp(philo, "%lo %i has taken the fork to his right\n");
	pthread_mutex_lock(philo->lfork);
	printp(philo, "%lo %i has taken the fork to his left\n");
	printp(philo, "%lo %i is eating\n");
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_unlock(philo->lfork);
}
