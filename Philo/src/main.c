#include "../inc/philo.h"

//si no tiene suficientes argumentos
void Usage() {
	write(1, "Not enough args\n", 17);
	exit(1);
}

int main(int argc, char **argv) {
	if (argc < 5) Usage();
	if (check_args(argc, argv) == 1) return(1);
	t_all program;
	pthread_mutex_lock(&program.lock);
	init_all(&program, argc, argv);
	pthread_mutex_unlock(&program.lock);
	if (thread_start(&program))
		return (ft_error("Fatal error ocurred", &program));
	ft_exit(&program); 
	return (0);
}