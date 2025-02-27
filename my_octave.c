#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main(void)
{
	char command;
	int nr_matrices = 0, arr_size = 1;
	int *col_arr, *line_arr;
	int ***mat_arr;

	while (1) {
		scanf(" %c", &command); // read command

		switch (command) { // execute command
		case 'L':
			load(&mat_arr, &nr_matrices, &arr_size, &line_arr, &col_arr);
			break;
		case 'D':
			display_dimensions(nr_matrices, line_arr, col_arr);
			break;
		case 'P':
			print(mat_arr, line_arr, col_arr, nr_matrices);
			break;
		case 'C':
			resize_matrix(&mat_arr, line_arr, col_arr, &nr_matrices);
			break;
		case 'M':
			multiply(&mat_arr, &line_arr, &col_arr, &nr_matrices, &arr_size);
			break;
		case 'O':
			sort_matrix_array(&mat_arr, line_arr, col_arr, nr_matrices);
			break;
		case 'T':
			transpose_matrix(&mat_arr, line_arr, col_arr, nr_matrices);
			break;
		case 'R':
			power(mat_arr, line_arr, col_arr, &nr_matrices);
			break;
		case 'F':
			erase_matrix(&mat_arr, line_arr, col_arr, &nr_matrices, &arr_size);
			break;
		case 'S':
			strassen_multiply(&mat_arr, &line_arr, &col_arr, &nr_matrices,
							  &arr_size);
			break;
		case 'Q':
			free_all(mat_arr, line_arr, col_arr, nr_matrices);
			return 0;
		default: // any other command is invalid
			printf("Unrecognized command\n");
			break;
		}
	}
}
