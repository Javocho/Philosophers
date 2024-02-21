#include "../inc/philo.h"

//si no tiene suficientes argumentos
void Usage() {
	write(1, "Not enough args\n", 17);
	exit(1);
}

static void	check_finish(t_all *program)
{
	int	i;

	i = 0;
	while (i < program->nfilos && program->dead == 0)
	{
		usleep(1000);
		if (program->philos[i].finished == 1)
			i++;
	}
	printf("Simulation ended after %i eats\n", program->philos[0].n_meals);
}

int main(int argc, char **argv) {
	if (argc < 5) Usage();
	if (check_args(argc, argv) == 1) return(1);
	t_all program;
	init_all(&program, argc, argv);
	if (thread_start(&program))
		return (ft_error("Fatal error ocurred", &program));
	if (program.philos[0].finished == 1 && program.dead == 0)
		check_finish(&program);
	ft_exit(&program);
	return (0);
}