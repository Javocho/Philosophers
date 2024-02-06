#include "../inc/philo.h"

int check_args(int argc, char **argv) {
	int i = -1;
	while (++i < argc) {
		if (ft_atoi(argv[i]) == 0)
			return (ft_error("Incorrect arg", NULL));
	}
}

unsigned int	ft_get_time() {
	struct timeval *Tp;
	if (gettimeofday(Tp, NULL) == -1)
		return (ft_error("gettimeofday error\n", NULL));
	return (Tp->tv_sec + Tp->tv_usec/1000000);
}

