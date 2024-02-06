#include "../inc/philo.h"

void	ft_sleep(unsigned int time)
{
	time += ft_get_time();
	while (ft_get_time() <= time)
		usleep(100);
}

int	show_state(char *str, t_philo *philo)
{
	t_all		*program;

	program = philo->program;
	if (program->dead == 0 /*&& ft_get_time() - program->init_time >= 0*/)
	{
		pthread_mutex_lock(&program->lock);
		if (program->dead == 0 && ft_get_time() - program->init_time >= 0)
			printf("%ld philo %i %s\n", ft_get_time() - program->init_time, philo->id, str);
		pthread_mutex_unlock(&program->lock);
	}
	return (0);
}

//State dead?

static void	ft_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_state("took a fork", philo);
	pthread_mutex_lock(philo->l_fork);
	print_state("took a fork", philo);
}

void	ft_eat(t_philo *philo)
{
	take_fork(philo);
	pthread_mutex_lock(&philo->lock);
	philo->eating = 1;
	print_state("is eating", philo);
	philo->time_to_die = ft_get_time() + philo->program->time_to_die;
	ft_usleep(philo->program->time_to_eat);
	philo->n_meals++;
	philo->eating = 0;
	pthread_mutex_unlock(&philo->lock);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	print_state("is sleeping", philo);
	ft_usleep(philo->program->time_to_sleep);
	print_state("is thinking", philo);
}