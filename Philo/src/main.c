#include "../inc/philo.h"

void Usage() {
	write(1, "Not enough args\n", 17);
	exit(1);
}

int main(int argc, char **argv) {
	if (argc < 5) Usage();
	//init
}