/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:19:12 by psoulie           #+#    #+#             */
/*   Updated: 2025/04/09 15:46:30 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static t_philo	*last_philo(t_philo *first, t_philo *prev, t_data *data, int id)
{
	t_philo *philo;

	philo = new_philo(prev, data, id);
	first->lfork = philo->rfork;
	philo->next = first;
	return (philo);
}

static t_philo	*new_philo(t_philo *prev, t_data *data, int id)
{
	t_philo	*philo;

	philo = first_philo(data);
	philo->id = id;
	philo->lfork = prev->rfork;
	return (philo);
}

static t_philo	*first_philo(t_data *data)
{
	t_philo	*philo;
	
	philo = malloc(sizeof(t_philo));
	philo->id = 1;
	philo->is_dead = 0;
	pthread_mutex_init(&(philo->rfork), NULL);
	philo->next = NULL;
	return (philo);
}

static t_philo	*philo_init(t_data *data)
{
	int		i;
	t_philo	*philo;
	t_philo	*save;

	philo = first_philo(data);
	save = philo;
	i = 2;
	while (i <= data->nbphilo)
	{
		if (i < data->nbphilo)
			philo->next = new_philo(philo, data, i);
		else
			philo->next = last_philo(save, philo, data, i);
		philo = philo->next;
		i++;
	}
	return (save);
}

void	run_philosophers(t_data *data)
{
	t_philo	*philo;

	philo = philo_init(data);

}
