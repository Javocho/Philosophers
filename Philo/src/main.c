/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:08:42 by fcosta-f          #+#    #+#             */
/*   Updated: 2024/03/02 13:10:20 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//si no tiene suficientes argumentos
void	usage(void)
{
	write(1, "Not enough args\n", 17);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_all	program;

	if (argc < 5)
		usage();
	if (check_args(argc, argv) == 1)
		return (1);
	pthread_mutex_lock(&program.lock);
	init_all(&program, argc, argv);
	pthread_mutex_unlock(&program.lock);
	if (thread_start(&program))
		return (ft_error("Fatal error ocurred", &program));
	ft_exit(&program);
	return (0);
}
