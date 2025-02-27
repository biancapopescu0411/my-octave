#include <stdio.h>
#include <stdlib.h>

#define MOD 10007

// function for reading and allocating an array
int *read_array(int size)
{
	// allocating memory for the array
	int *arr = (int *)malloc((size) * sizeof(int));
	if (!arr) { // checking if the memory was allocated
		printf("Error allocating memory!\n");
		return NULL;
	}

	// reading the array
	for (int i = 0; i < size; i++)
		scanf("%d", &arr[i]);

	return arr;
}

// function for allocating a matrix
int **alloc_matrix(int nr_lines, int nr_columns)
{
	//allocating memory for the matrix
	int **mat = (int **)calloc(nr_lines, sizeof(int *));
	if (!mat) { // checking if the memory was allocated
		printf("Error allocating memory!\n");

		return NULL;
	}

	// allocating memory for each line of the matrix
	for (int i = 0; i < nr_lines; i++) {
		mat[i] = (int *)calloc(nr_columns, sizeof(int));
		if (!mat[i]) {
			printf("Error allocating memory!\n");

			return NULL;
		}
	}

	return mat;
}

// function for reading and allocating a matrix
void read_matrix(int ***mat, int *nr_lines, int *nr_columns)
{
	scanf("%d", nr_lines); // reading the number of lines
	scanf("%d", nr_columns); // reading the number of columns

	*mat = alloc_matrix(*nr_lines, *nr_columns); // allocating the matrix
	if (!(*mat)) { // checking if the memory was allocated
		printf("Error allocating memory!\n");

		return;
	}

	// reading the matrix
	for (int i = 0; i < *nr_lines; i++) {
		for (int j = 0; j < *nr_columns; j++)
			scanf("%d", &(*mat)[i][j]);
	}
}

// function for allocating / reallocating a matrix array
void realloc_array(int ****mat_arr, int nr_matrices, int *arr_size,
				   int **line_arr, int **col_arr)
{
	// if the array is empty, allocate memory for it
	if (nr_matrices == 0) {
		*mat_arr = (int ***)malloc((*arr_size) * sizeof(int **));
		if (!(*mat_arr)) {
			printf("Error allocating memory!\n");

			return;
		}

		// allocating memory for the arrays of lines and columns as well
		*line_arr = (int *)malloc((*arr_size) * sizeof(int));
		if (!(*line_arr)) {
			printf("Error allocating memory!\n");

			return;
		}

		*col_arr = (int *)malloc((*arr_size) * sizeof(int));
		if (!(*col_arr)) {
			printf("Error allocating memory!\n");

			return;
		}
	}

	// if the array is full, double its size
	if (nr_matrices == *arr_size) {
		*arr_size = ((*arr_size) * 2);

		*mat_arr = (int ***)realloc(*mat_arr, (*arr_size) * sizeof(int **));
		if (!(*mat_arr)) {
			printf("Error reallocating matrix!\n");

			return;
		}

		*line_arr = (int *)realloc(*line_arr, (*arr_size) * sizeof(int));
		if (!(*line_arr)) {
			printf("Error reallocating line!\n");

			return;
		}

		*col_arr = (int *)realloc(*col_arr, (*arr_size) * sizeof(int));
		if (!(*col_arr)) {
			printf("Error reallocating memory!\n");

			return;
		}
	}
}

// function for adding a matrix to the matrix array
void add_matrix(int **mat, int ****mat_arr, int nr_lines, int nr_columns,
				int *nr_matrices, int **line_arr, int **col_arr)
{
	(*mat_arr)[*nr_matrices] = mat; // adding the matrix to the array
	(*line_arr)[*nr_matrices] = nr_lines; // adding the number of lines
	(*col_arr)[*nr_matrices] = nr_columns; // adding the number of columns

	(*nr_matrices)++; // increasing the number of matrices
}

// function for loading a matrix (command L)
void load(int ****mat_arr, int *nr_matrices, int *arr_size, int **line_arr,
		  int **col_arr)
{
	int nr_lines, nr_columns;
	int **mat;

	read_matrix(&mat, &nr_lines, &nr_columns); // reading the matrix

	//reallocating the array if necessary
	realloc_array(mat_arr, *nr_matrices, arr_size, line_arr, col_arr);

	// adding the matrix to the array
	add_matrix(mat, mat_arr, nr_lines, nr_columns, nr_matrices, line_arr,
			   col_arr);
}

// function for displaying the dimensions of a matrix (command D)
void display_dimensions(int nr_matrices, int *line_arr, int *col_arr)
{
	int index;
	scanf("%d", &index); // reading the index of the matrix to be displayed

	if (index >= nr_matrices) { // checking if the index is valid
		printf("No matrix with the given index\n");

		return;
	}

	// displaying the dimensions
	printf("%d %d\n", line_arr[index], col_arr[index]);
}

// function for calculating the sum of the elements of a matrix
int sum(int **mat, int nr_lines, int nr_columns)
{
	int sum = 0;

	for (int i = 0; i < nr_lines; i++) {
		for (int j = 0; j < nr_columns; j++) {
			sum += mat[i][j]; // adding the element to the sum
			sum %= MOD; // calculating the modulo

			if (mat[i][j] < 0) // if the element is negative, add MOD
				sum += MOD;
		}
	}

	sum %= MOD;

	return sum;
}

// function for sorting the matrix array (command O)
void sort_matrix_array(int ****mat_arr, int *line_arr, int *col_arr,
					   int nr_matrices)
{
	int **aux_mat; // auxiliary matrix
	int aux_line, aux_col;

	for (int i = 0; i < nr_matrices - 1; i++) {
		for (int j = i + 1; j < nr_matrices; j++) {
			if (sum((*mat_arr)[i], line_arr[i], col_arr[i])
			> sum((*mat_arr)[j], line_arr[j], col_arr[j])) {
				aux_mat = (*mat_arr)[i];
				(*mat_arr)[i] = (*mat_arr)[j];
				(*mat_arr)[j] = aux_mat;

				// swapping the number of lines and columns as well
				aux_line = line_arr[i];
				line_arr[i] = line_arr[j];
				line_arr[j] = aux_line;

				aux_col = col_arr[i];
				col_arr[i] = col_arr[j];
				col_arr[j] = aux_col;
			}
		}
	}
}

// function for printing a matrix (command P)
void print(int ***mat_arr, int *line_arr, int *col_arr, int nr_matrices)
{
	int index;
	scanf("%d", &index); // reading the index of the matrix to be printed

	if (index >= nr_matrices || index < 0) { // checking if the index is valid
		printf("No matrix with the given index\n");

		return;
	}

	// printing the matrix
	for (int i = 0; i < line_arr[index]; i++) {
		for (int j = 0; j < col_arr[index]; j++)
			printf("%d ", mat_arr[index][i][j]);

		printf("\n");
	}
}

// function for multiplying two matrices (command M)
void multiply(int ****mat_arr, int **line_arr, int **col_arr, int *nr_matrices,
			  int *arr_size)
{
	int index1, index2; // indices of the matrices to be multiplied

	scanf("%d", &index1); // reading the first index
	scanf("%d", &index2); // reading the second index

	// checking if the indices are valid
	if (index1 >= *nr_matrices || index2 >= *nr_matrices) {
		printf("No matrix with the given index\n");

		return;
	}

	// checking if the matrices can be multiplied
	if ((*col_arr)[index1] != (*line_arr)[index2]) {
		printf("Cannot perform matrix multiplication\n");

		return;
	}

	// allocating memory for the result matrix
	int **result = (int **)calloc((*line_arr)[index1], sizeof(int *));

	// allocating memory for each line of the result matrix
	for (int i = 0; i < (*line_arr)[index1]; i++)
		result[i] = (int *)calloc((*col_arr)[index2], sizeof(int));

	// multiplying the matrices
	for (int i = 0; i < (*line_arr)[index1]; i++) {
		for (int j = 0; j < (*col_arr)[index2]; j++) {
			for (int k = 0; k < (*col_arr)[index1]; k++) {
				result[i][j] += ((*mat_arr)[index1][i][k]
				* (*mat_arr)[index2][k][j]);

				result[i][j] %= MOD;

				if (result[i][j] < 0)
					result[i][j] += MOD;
			}
		}
	}

	// adding the result matrix to the array
	realloc_array(mat_arr, *nr_matrices, arr_size, line_arr, col_arr);
	add_matrix(result, mat_arr, (*line_arr)[index1], (*col_arr)[index2],
			   nr_matrices, line_arr, col_arr);
}

// function for freeing the memory allocated for a matrix
void free_matrix(int **mat, int nr_lines)
{
	for (int i = 0; i < nr_lines; i++)
		free(mat[i]);
	free(mat);
}

// function for freeing the memory allocated for the matrix array
void free_all(int ***mat_arr, int *line_arr, int *col_arr, int nr_matrices)
{
	for (int i = 0; i < nr_matrices; i++)
		free_matrix(mat_arr[i], line_arr[i]);

	if (nr_matrices > 0) {
		free(mat_arr);
		free(line_arr);
		free(col_arr);
	}
}

// function for transposing a matrix (command T)
void transpose_matrix(int ****mat_arr, int *line_arr, int *col_arr,
					  int nr_matrices)
{
	int index;
	scanf("%d", &index); // reading the index of the matrix to be transposed

	// checking if the index is valid
	if (index >= nr_matrices || index < 0) {
		printf("No matrix with the given index\n");

		return;
	}

	// allocating memory for the result matrix
	int **result = alloc_matrix(col_arr[index], line_arr[index]);
	if (!result) { // checking if the memory was allocated
		printf("Error allocating memory!\n");

		return;
	}

	// transposing the matrix
	for (int i = 0; i < col_arr[index]; i++) {
		for (int j = 0; j < line_arr[index]; j++)
			result[i][j] = (*mat_arr)[index][j][i];
	}

	// freeing the memory allocated for the initial matrix
	free_matrix((*mat_arr)[index], line_arr[index]);

	(*mat_arr)[index] = result; // adding the result matrix to the array

	// swapping the number of lines and columns
	int aux = line_arr[index];
	line_arr[index] = col_arr[index];
	col_arr[index] = aux;
}

// function for erasing a matrix (command F)
void erase_matrix(int ****mat_arr, int *line_arr, int *col_arr,
				  int *nr_matrices, int *arr_size)
{
	int index;
	scanf("%d", &index); // reading the index of the matrix to be erased

	if (index >= *nr_matrices || index < 0) { // checking if the index is valid
		printf("No matrix with the given index\n");
		return;
	}

	// freeing the memory allocated for the matrix
	for (int i = 0; i < line_arr[index]; i++)
		free((*mat_arr)[index][i]);
	free((*mat_arr)[index]);

	// shifting the matrices to the left
	for (int i = index; i < (*nr_matrices) - 1; i++) {
		(*mat_arr)[i] = (*mat_arr)[i + 1];
		line_arr[i] = line_arr[i + 1];
		col_arr[i] = col_arr[i + 1];
	}

	(*nr_matrices)--; // decreasing the number of matrices

	if (*nr_matrices == 0) { // if there are no matrices left, free the arrays
		free(*mat_arr);
		free(line_arr);
		free(col_arr);

		*arr_size = 1; // reset the size of the array
	}
}

// function for resizing a matrix (command C)
void resize_matrix(int ****mat_arr, int *line_arr, int *col_arr,
				   int *nr_matrices)
{
	int index;
	scanf("%d", &index); // reading the index of the matrix to be resized

	int nr_lines, nr_columns;

	scanf("%d", &nr_lines); // reading the number of lines of the new matrix
	int *line = read_array(nr_lines); // reading the lines to be kept

	scanf("%d", &nr_columns);
	int *col = read_array(nr_columns);

	// checking if the index is valid
	if (index >= *nr_matrices || index < 0) {
		printf("No matrix with the given index\n");

		free(line);
		free(col);

		return;
	}

	// allocating memory for the result matrix
	int **result = alloc_matrix(nr_lines, nr_columns);

	// resizing the matrix according to the given lines and columns
	for (int i = 0; i < nr_lines; i++) {
		for (int j = 0; j < nr_columns; j++)
			result[i][j] = (*mat_arr)[index][line[i]][col[j]];
	}

	// freeing the memory allocated for the initial matrix
	free_matrix((*mat_arr)[index], line_arr[index]);

	(*mat_arr)[index] = result; // adding the result matrix to the array
	line_arr[index] = nr_lines; // updating the number of lines
	col_arr[index] = nr_columns; // updating the number of columns

	free(line); // freeing the memory allocated for the lines and columns
	free(col);
}

// helper function for calculating the power of a matrix
int **calculate_aux_matrix(int ***mat_arr, int *line_arr, int *col_arr,
						   int index, int **result)
{
	// allocating memory for the auxiliary matrix
	int **aux = alloc_matrix(line_arr[index], col_arr[index]);

	// calculating the auxiliary matrix
	for (int i = 0; i < line_arr[index]; i++) {
		for (int j = 0; j < col_arr[index]; j++) {
			for (int k = 0; k < col_arr[index]; k++) {
				aux[i][j] += (result[i][k] * mat_arr[index][k][j]) % MOD;
				aux[i][j] %= MOD;

				if (aux[i][j] < 0)
					aux[i][j] += MOD;
			}
		}
	}

	// freeing the memory allocated for the result matrix
	free_matrix(result, line_arr[index]);

	return aux;
}

// function for calculating the power of a matrix in O(log n) (command R)
void power(int ***mat_arr, int *line_arr, int *col_arr, int *nr_matrices)
{
	int index, power;

	scanf("%d", &index); // reading the index of the matrix to be powered
	scanf("%d", &power); // reading the power

	if (index >= *nr_matrices || index < 0) { // checking if the index is valid
		printf("No matrix with the given index\n");
		return;
	}

	if (power < 0) { // checking if the power is valid
		printf("Power should be positive\n");
		return;
	}

	// checking if the matrix is square
	if (line_arr[index] != col_arr[index]) {
		printf("Cannot perform matrix multiplication\n");
		return;
	}

	// allocating memory for the result matrix
	int **result = alloc_matrix(line_arr[index], col_arr[index]);

	// putting 1 on the main diagonal and 0 everywhere else
	for (int i = 0; i < line_arr[index]; i++) {
		for (int j = 0; j < col_arr[index]; j++) {
			if (i == j)
				result[i][j] = 1;
			else
				result[i][j] = 0;
		}
	}

	while (power) {
		if (power % 2 == 1) { // if the power is odd, multiply the result
			int **aux = calculate_aux_matrix(mat_arr, line_arr, col_arr,
			index, result);

			result = aux; // updating the result matrix
		}

		int **aux = calculate_aux_matrix(mat_arr, line_arr, col_arr,
		index, mat_arr[index]);

		mat_arr[index] = aux;

		power /= 2;
	}

	free_matrix(mat_arr[index], line_arr[index]);

	mat_arr[index] = result;
}

// function for multiplying two matrices using Strassen's algorithm (command S)
void strassen_multiply(int ****mat_arr, int **line_arr, int **col_arr,
					   int *nr_matrices, int *arr_size)
{
	int i, j, k;
	int index1, index2;

	scanf("%d", &index1);
	scanf("%d", &index2);

	if (index1 >= *nr_matrices || index2 >= *nr_matrices ||
		index1 < 0 || index2 < 0) {
		printf("No matrix with the given index\n");
		return;
	}

	if ((*col_arr)[index1] != (*line_arr)[index2]) {
		printf("Cannot perform matrix multiplication\n");
		return;
	}

	int **result = (int **)calloc((*line_arr)[index1], sizeof(int *));

	for (i = 0; i < (*line_arr)[index1]; i++)
		result[i] = (int *)calloc((*col_arr)[index2], sizeof(int));

	for (i = 0; i < (*line_arr)[index1]; i++) {
		for (j = 0; j < (*col_arr)[index2]; j++) {
			for (k = 0; k < (*col_arr)[index1]; k++) {
				result[i][j] += ((*mat_arr)[index1][i][k]
				* (*mat_arr)[index2][k][j]);
				result[i][j] %= MOD;
				if (result[i][j] < 0)
					result[i][j] += MOD;
			}
		}
	}

	realloc_array(mat_arr, *nr_matrices, arr_size, line_arr, col_arr);
	add_matrix(result, mat_arr, (*line_arr)[index1], (*col_arr)[index2],
			   nr_matrices, line_arr, col_arr);
}
