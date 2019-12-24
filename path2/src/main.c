#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

int main(int argc, char *argv[]) {
	char **ostrovi = NULL;
	int **matrix = NULL;

	if (mx_errors_check(argc, argv[1]) == 0) {
		return 0;
	} else if (mx_first_line(argv[1]) == 0) {
		return 0;
	} else if (mx_errors_format(argv[1]) == 0) {
		return 0;
	} 
	mx_loop(argv[1]);
	ostrovi = mx_errors_isl(argv[1]);
	if (ostrovi == 0) 
		return 0;
	matrix = mx_matrix_graph(argv[1], ostrovi);
	mx_algorithm(matrix, argv[1], ostrovi);
	return 0;
}
