#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef	struct s_data
{
	int		nbphilo;
	int		tdie;
	int		teat;
	int		tsleep;
	int		nbeat;
	long	start_time;
}				t_data;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				is_dead;
	int				teat;
	int				tsleep;
	int				nbeaten;
	long			last_meal;
	long			start_time;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*print;
	struct s_philo	*next;
}				t_philo;

// philo
void	philosophers(t_data *data);

// run
void	printp(t_philo *philo, char *str);

// utils
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
long	get_new_time(t_philo *philo);
long	get_time(void);

#endif