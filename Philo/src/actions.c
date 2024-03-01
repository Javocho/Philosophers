#include "../inc/philo.h"

//para dormir la cantidad de segundos time. 
void	ft_sleep(unsigned int time)
{
	time += ft_get_time(); //para tener tiempo final
	while (ft_get_time() <= time)
		usleep(100);
}

//per a imprimir estat d'un philosof
int	show_state(char *str, t_philo *philo)
{
	t_all		*program;

	program = philo->program;
	pthread_mutex_lock(&program->monitorize);
	if (program->dead == 0) 
	{
		if (program->dead == 0)
			printf("%u philo %i %s\n", ft_get_time() - program->init_time, philo->id, str);
		pthread_mutex_unlock(&program->monitorize);
	}
	return (0);
}

//imprimir estat de filosof mort i posar program dead a 1
int	show_state_dead(char *str, t_philo *philo)
{
	long int	actual_time;
	t_all		*program;

	program = philo->program;
	pthread_mutex_lock(&program->monitorize);
	actual_time = ft_get_time();
	actual_time = actual_time - program->init_time;
	if (program->dead == 0)
		printf("%lu philo %i %s\n", actual_time, philo->id, str);
	philo->program->dead = 1;
	pthread_mutex_unlock(&program->monitorize);
	ft_sleep(300);
	return (0);
}


//agafar forquilles
static void	ft_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	show_state("took a fork", philo);
	pthread_mutex_lock(philo->l_fork);
	show_state("took a fork", philo);
}

//eat, sleep, think, cycle
void	ft_eat(t_philo *philo)
{
	ft_forks(philo);
	pthread_mutex_lock(&philo->lock);
	philo->eating = 1;
	show_state("is eating", philo);
	philo->time_to_die = ft_get_time() + philo->program->time_to_die;
	ft_sleep(philo->program->time_to_eat);
	philo->n_meals++;
	philo->eating = 0;
	pthread_mutex_unlock(&philo->lock);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	show_state("is sleeping", philo);
	ft_sleep(philo->program->time_to_sleep);
	show_state("is thinking", philo);
}