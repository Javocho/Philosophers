#include "../inc/philo.h"

int check_args(int argc, char **argv) {
	int i = -1;
	while (++i < argc) {
		if (ft_atoi(argv[i]) == 0)
			return (ft_error("Incorrect arg", NULL));
	}
}