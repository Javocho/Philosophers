/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:59:07 by fcosta-f          #+#    #+#             */
/*   Updated: 2024/03/02 13:33:18 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_philo
{
	struct s_all	*program;
	pthread_t		thread;
	int				id;
	int				eating;
	int				n_meals;
	int				die_time;
	int				finished;
	unsigned int	time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

typedef struct s_all
{
	pthread_t		*th_filo;
	pthread_t		t1;
	int				nfilos;
	int				total_meals;
	int				dead;
	int				finish;
	t_philo			*philos;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	init_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	monitorize;
	pthread_mutex_t	mutex_time_die;
}	t_all;

int				check_args(int argc, char **argv);
int				init_all(t_all *program, int argc, char **argv);
unsigned int	ft_get_time(void);
int				thread_start(t_all *program);
void			ft_exit(t_all *program);
int				ft_error(char *s, t_all *program);
void			ft_sleep(unsigned int time);
int				show_state(char *str, t_philo *philo);
int				show_state_dead(char *str, t_philo *philo);
void			ft_eat(t_philo *philo);
int				ft_atoi(const char *str);	

#endif
