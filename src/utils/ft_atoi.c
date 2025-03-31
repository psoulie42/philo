/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:37:23 by psoulie           #+#    #+#             */
/*   Updated: 2025/03/31 15:40:15 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static int	ftstrncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < n - 1 && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	isminus(char a)
{
	if (a == '-')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	if (ftstrncmp(str, "2147483647", 10) == 0)
		return (2147483647);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		neg = isminus(str[i]);
		i++;
	}
	res = 0;
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		res *= 10;
		res += (str[i] - 48);
		i++;
	}
	if (neg == 1)
		res *= -1;
	return (res);
}
