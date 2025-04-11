#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
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
	int				*is_dead;
	int				teat;
	int				tsleep;
	int				nbeaten;
	long			last_meal;
	long			start_time;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	rfork;
	pthread_mutex_t	death;
	pthread_mutex_t	print;
	struct s_philo	*next;
}				t_philo;

// philo
t_philo	*philo_init(t_data *data);
void	create_threads(t_philo *philo);

// run
int		monitoring(t_data *data, t_philo *philo);
void	run_philo(t_data *data);
void	*routine(void *etst);
void	printp(t_philo *philo, char *str);
void	is_dead(t_philo **philo);

// actions
void	philo_eat(t_philo *philo);
void	philo_eat_even(t_philo *philo);
void	philo_eat_odd(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

// end
int		check_death(t_philo *philo);
void	end_philo(t_data *data, t_philo *philo);

// utils
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
long	get_new_time(long start_time);
long	get_time(void);

#endif
