/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:37:27 by psoulie           #+#    #+#             */
/*   Updated: 2025/05/05 17:30:42 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	solo_philo(t_data *data)
{
	long	time;

	time = get_new_time(data->start_time);
	printf("%li %i %s\n", time, 1, \
			"has taken the fork to his right");
	while (get_new_time(data->start_time) - time < data->tdie)
		usleep(42);
	printf("%li %i %s\n", get_new_time(data->start_time), 1, "has died");
}

static t_data	*data_check(t_data *data)
{
	if ((data->nbphilo <= 0 || data->nbphilo > 200) || \
			data->tdie <= 0 || \
			data->teat <= 0 || \
			data->tsleep <= 0)
		return (free(data), NULL);
	else
		data->nbeat = 0;
	return (data);
}

static t_data	*data_init(char **av)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	data->nbphilo = ft_atoi(av[1]);
	data->tdie = ft_atoi(av[2]);
	data->teat = ft_atoi(av[3]);
	data->tsleep = ft_atoi(av[4]);
	data->is_dead = 0;
	pthread_mutex_init(&data->death, NULL);
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->meal, NULL);
	data = data_check(data);
	if (av[5])
		data->nbeat = ft_atoi(av[5]);
	return (data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac < 5)
		return (printf("too few arguments\n"), 1);
	if (ac > 6)
		return (printf("too many arguments\n"), 1);
	if (av[5] && ft_atoi(av[5]) <= 0)
		return (printf("invalid data\n"), 1);
	data = data_init(av);
	if (!data)
		return (printf("invalid data\n"), 1);
	data->start_time = get_time();
	if (data->nbphilo == 1)
	{
		solo_philo(data);
		return (0);
	}
	run_philo(data);
	return (0);
}
