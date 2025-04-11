/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:01:05 by psoulie           #+#    #+#             */
/*   Updated: 2025/04/11 14:01:51 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	ft_sleep(int time, t_philo *philo)
{
	long	start;
	
	start = get_new_time(philo->start_time);
	while (get_new_time(philo->start_time) - start < time)
		usleep(100);
}

long	get_new_time(long start_time)
{
	return (get_time() - start_time);
}

long	get_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
