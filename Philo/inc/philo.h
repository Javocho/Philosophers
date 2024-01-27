#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
#include "../libs/libft/libft.h"

typedef struct s_philo
{
	struct s_all *program;
	pthread_t	thread;
	int			id;
	int			eating;
	int			n_meals;
	int			last_meal;
	int			status;
	pthread_mutex_t lock;
	pthread_mutex_t *r_fork;
	pthread_mutex_t *l_fork;
}	t_philo;


typedef struct s_all
{
	pthread_t *th_filo;
	int			nfilos;
	t_philo		*philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			total_meals;
	int			finish;
	pthread_mutex_t lock;
	pthread_mutex_t monitorize;
	pthread_mutex_t *forks;
}	t_all;


int check_args(int argc, char **argv);
int init_all(t_all *program, int argc, char **argv);


#endif