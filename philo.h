#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>

typedef	struct s_data
{
	int	nbphilo;
	int	tdie;
	int	teat;
	int	tsleep;
	int	nbeat;
}				t_data;


int	ft_atoi(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif