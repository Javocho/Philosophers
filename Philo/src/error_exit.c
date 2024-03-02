/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:04:50 by fcosta-f          #+#    #+#             */
/*   Updated: 2024/03/02 13:10:29 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"


//auxiliat function to print error
int	ft_error(char *s, t_all *program)
{
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

	i = 0;
	while (i < program->nfilos)
	{
		pthread_mutex_destroy(&program->forks[i]);
		pthread_mutex_destroy(&program->philos[i].lock);
		i++;
	}
	pthread_mutex_destroy(&program->monitorize);
	pthread_mutex_destroy(&program->lock);
	ft_clear(program);
}
