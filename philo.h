#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef	struct s_data
{
	int	nbphilo;
	int	tdie;
	int	teat;
	int	tsleep;
	int	nbeat;
}				t_data;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				is_dead;
	long			last_meal;
	pthread_mutex_t	lfork;
	pthread_mutex_t	rfork;
	struct s_philo	*next;
}				t_philo;

// philo
void	run_philosophers(t_data *data);

// utils
int	ft_atoi(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif