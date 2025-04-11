/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:30:25 by psoulie           #+#    #+#             */
/*   Updated: 2025/04/11 11:38:53 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	is_dead(t_philo **philo)
{
	pthread_mutex_lock(&((*philo)->death));
	*((*philo)->is_dead) = 1;
	pthread_mutex_lock(&((*philo)->death));
}

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
				return (is_dead(&philo), 0);
		}
		if (get_new_time(philo->start_time) - philo->last_meal > data->tdie)
			return (printp(philo, "has died"), is_dead(&philo), philo->id);
		philo = philo->next;
	}
	return (-1);
}

void	printp(t_philo *philo, char *str)
{
	pthread_mutex_lock(&(philo->death));
	if (philo->is_dead == 0)
	{
		pthread_mutex_lock(&(philo->print));
		printf("%lo %i %s\n", get_new_time(philo->start_time), philo->id, str);
		pthread_mutex_unlock(&(philo->print));
	}
	pthread_mutex_unlock(&(philo->death));
}

void	*routine(void *etst)
{
	t_philo *philo;
	
	philo = (t_philo *)etst;
	if (philo->id % 2 == 0)
		usleep(20);
	while (!check_death(philo))
	{
		philo_eat(philo);
		philo->last_meal = get_new_time(philo->start_time);
		philo->nbeaten++;
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
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
	end_philo(data, philo);
}
