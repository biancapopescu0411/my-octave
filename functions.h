#pragma once

int *read_array(int size);
void read_matrix(int ***mat, int *nr_lines, int *nr_columns);
void realloc_array(int ****mat_arr, int nr_matrices, int *arr_size,
				   int **line_arr, int **col_arr);
void add_matrix(int **mat, int ****mat_arr, int nr_lines, int nr_columns,
				int *nr_matrices, int **line_arr, int **col_arr);
void load(int ****mat_arr, int *nr_matrices, int *arr_size, int **line_arr,
		  int **col_arr);
void display_dimensions(int nr_matrices, int *line_arr, int *col_arr);
int sum(int **mat, int nr_lines, int nr_columns);
void print(int ***mat_arr, int *line_arr, int *col_arr, int nr_matrices);
void multiply(int ****mat_arr, int **line_arr, int **col_arr, int *nr_matrices,
			  int *arr_size);
void power(int ***mat_arr, int *line_arr, int *col_arr, int *nr_matrices);
void free_matrix(int **mat, int nr_lines);
void transpose_matrix(int ****mat_arr, int *line_arr, int *col_arr,
					  int nr_matrices);
void free_all(int ***mat_arr, int *line_arr, int *col_arr, int nr_matrices);
void erase_matrix(int ****mat_arr, int *line_arr, int *col_arr,
				  int *nr_matrices, int *arr_size);
void sort_matrix_array(int ****mat_arr, int *line_arr, int *col_arr,
					   int nr_matrices);
void resize_matrix(int ****mat_arr, int *line_arr, int *col_arr,
				   int *nr_matrices);
void strassen_multiply(int ****mat_arr, int **line_arr, int **col_arr,
					   int *nr_matrices, int *arr_size);
int **calculate_aux_matrix(int ***mat_arr, int *line_arr, int *col_arr,
						   int index, int **result);
