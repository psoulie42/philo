/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:30:25 by psoulie           #+#    #+#             */
/*   Updated: 2025/04/10 14:14:55 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	monitoring(t_data *data, t_philo *philo)
{
	int	first;

	while (1)
	{
		if (data->nbeat)
		{
			first = philo->id;
			philo = philo->next;
			while (philo->nbeaten >= data->nbeat && philo->id != first)
				philo = philo->next;
			if (philo->id == first)
				return (0);
		}
		if (get_new_time(philo->start_time) - philo->last_meal > data->tdie)
			return (printp(philo, "has died"), philo->is_dead = 1, philo->id);
		philo = philo->next;
	}
	return (-1);
}

void	printp(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->print);
	printf("%lo %i %s\n", get_new_time(philo->start_time), philo->id, str);
	pthread_mutex_unlock(philo->print);
}

void	*routine(t_philo *philo)
{
	while (1)
	{
		philo_eat(philo);
		philo->last_meal = get_new_time(philo->start_time);
		philo->nbeaten++;
		philo_sleep(philo);
		philo_think(philo);
	}
}

void	run_philo(t_data *data)
{
	t_philo	*philo;
	int		status;

	philo = philo_init(data);
	create_threads(philo);
	status = monitoring(data, philo);
	if (status == -1)
		printf("wait wtf\n");
	else if (status == 0)
		printf("all philosophers have eaten %i times\n", data->nbeat);
}
