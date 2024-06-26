/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:10:35 by fcosta-f          #+#    #+#             */
/*   Updated: 2024/03/02 14:34:28 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//to check if there's a philo dead
void	*supervisor(void *program_ptr)
{
	t_all	*program;
	int		i;

	i = 0;
	program = (t_all *)program_ptr;
	ft_sleep(program->time_to_die - (program->time_to_die / 4));
	pthread_mutex_unlock(&program->lock);
	while (i++ < program->nfilos && program->dead == 0 && program->finish == 0)
	{
		pthread_mutex_lock(&program->philos[i].lock);
		if (i == program->nfilos)
			i = 0;
		if (program->philos[i].eating == 0)
		{
			if ((ft_get_time() >= program->philos[i].time_to_die) && program->philos[i].eating == 0 && program->philos[i].finished == 0)
				show_state_dead("DIED", &program->philos[i]);
		}

		pthread_mutex_unlock(&program->lock);
		pthread_mutex_unlock(&program->philos[i].lock);
		if (program->philos[i].finished == 1)
			break ;
	}
	return (NULL);
}

//tasks to do in every philo thread
void	*tasks(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	pthread_mutex_lock(&philo->lock);
	if (philo->id % 2 != 0)
		ft_sleep(philo->program->time_to_eat / 10);
	pthread_mutex_lock(&philo->program->lock);
	philo->time_to_die = philo->program->time_to_die + ft_get_time();
	pthread_mutex_lock(&philo->program->monitorize);
	while (philo->program->dead == 0)
	{
		pthread_mutex_unlock(&philo->program->monitorize);
		//pthread_mutex_lock(&philo->lock);
		ft_eat(philo);
		pthread_mutex_lock(&philo->program->lock);
		if (philo->n_meals == philo->program->total_meals && philo->program->total_meals != -1)
			break ;
		pthread_mutex_lock(&philo->program->monitorize);
	}
	if (philo->n_meals == philo->program->total_meals)
	{
		// show_state("ACABAO", philo);
		philo->finished = 1;
	}
	pthread_mutex_unlock(&philo->lock);
	pthread_mutex_unlock(&philo->program->lock);
	return (NULL);
}

//Start the thread tasks in every philo
int	thread_start(t_all *program)
{
	int	i;

	if (program->nfilos == 1)
	{
		pthread_mutex_lock(program->philos[0].l_fork);
		show_state("took a fork", &program->philos[0]);
		ft_sleep(program->time_to_die);
		show_state_dead("DIED", &program->philos[0]);
		pthread_mutex_unlock(program->philos[0].l_fork);
		return (0);
	}
	program->init_time = ft_get_time();
	i = 0;
	while (i < program->nfilos)
	{
		if (pthread_create(&program->th_filo[i], NULL, &tasks, &program->philos[i]) != 0)
			return (ft_error("Error thread", program));
		i++;
	}
	supervisor(program);
	// if (pthread_create(&program->t1, NULL, &supervisor, program))
	// 	return (ft_error("Error thread", program));
	i = 0;
	pthread_join(program->t1, NULL);
	while (i < program->nfilos && program->dead == 0)
	{
		pthread_join(program->th_filo[i], NULL);
		i++;
	}
	return (0);
}
