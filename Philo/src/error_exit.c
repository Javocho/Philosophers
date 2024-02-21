#include "../inc/philo.h"


//auxiliat function to print error
int ft_error(char *s, t_all *program) {
	printf("%s\n", s);
	if (program) 
		ft_exit(program);
	return (1);
}

void	ft_clear(t_all	*program)
{
	if (program->th_filo)
		free(program->th_filo);
	if (program->forks)
		free(program->forks);
	if (program->philos)
		free(program->philos);
}


void	ft_exit(t_all *program)
{
	int	i;

	i = -1;
	while (++i < program->nfilos)
	{
		pthread_mutex_destroy(&program->forks[i]);
		pthread_mutex_destroy(&program->philos[i].lock);
	}
	pthread_mutex_destroy(&program->monitorize);
	pthread_mutex_destroy(&program->lock);
	ft_clear(program);
}