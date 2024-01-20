#include "../inc/philo.h"

static int arrays_alloc(t_all *program) {
	program->th_filo = malloc(sizeof(pthread_t) * program->nfilos);
	if (!program->th_filo) ft_error("error allocating", program);
	program->philos = malloc(sizeof(t_philo) * program->nfilos);
	if (!program->philos) ft_error("error allocating", program);
	program->forks = malloc(sizeof(pthread_mutex_t) * program->nfilos);
	if (!program->forks) ft_error("error allocating", program);
	return (0);
}

static int init_philos(t_all *program) {
	int i;
	i = -1;
	while (++i < program->nfilos) {
		program->philos[i]
	}
}

static int init_forks(t_all *program) {

}

int init_all(t_all *program, int argc, char **argv) {
	if (check_args(argc, argv) == 1) return (1);
	program->nfilos = ft_atoi(argv[1]);
	program->time_to_die = ft_atoi(argv[2]);
	program->time_to_eat = ft_atoi(argv[3]);
	program->time_to_sleep = ft_atoi(argv[4]);
	if (argc > 5) program->total_meals = ft_atoi(argv[6]);
	else program->total_meals = -1;
	program->finish = 0;
	pthread_mutex_init(&program->lock, NULL);
	pthread_mutex_init(&program->monitorize, NULL);
	if (arrays_alloc(program)) return (1);

}