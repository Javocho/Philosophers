#include "../inc/philo.h"

void Usage() {
	write(1, "Not enough args\n", 17);
	exit(1);
}

int main(int argc, char **argv) {
	if (argc < 5) Usage();
	if (check_args(argc, argv) == 1) return(1);
	t_all program;
	init_all(&program, argc, argv);
	
}