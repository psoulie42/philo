/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:09:09 by psoulie           #+#    #+#             */
/*   Updated: 2025/04/10 16:10:36 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	free_philo(t_philo *philo, t_data *data)
{
	t_philo	*save;

	pthread_mutex_destroy(&(philo->death));
	pthread_mutex_destroy(&(philo->print));
	pthread_mutex_destroy(&(philo->rfork));
	while (data->nbphilo)
	{
		save = philo;
		philo = philo->next;
		free(save);
		data->nbphilo--;
	}
}

static void	join_threads(t_philo *philo)
{
	int	first;

	first = philo->id;
	pthread_join(philo->thread, NULL);
	philo = philo->next;
	while (philo->id != first)
	{
		pthread_join(philo->thread, NULL);
		philo = philo->next;
	}
}

void	end_philo(t_data *data, t_philo *philo)
{
	join_threads(philo);
	free_philo(philo, data);
	free(data);
}
