# MY OCTAVE

This C program provides a set of matrix operations, including matrix
multiplication, power calculation, sorting, resizing, and more. The program
uses dynamic memory allocation to handle matrices and matrix arrays of varying
sizes.

## Commands

The program accepts the following commands, which are read in `my_octave.c`:

* **L (load)** : Read and load a matrix into the matrix array.
* **D (display dimensions)** : Display the dimensions of a matrix.
* **O (sort)** : Sort the matrix array based on the sum of each matrix's
elements.
* **P (print)** : Print a matrix.
* **M (multiply)** : Multiply two matrices.
* **T (transpose)** : Transpose a matrix.
* **F (erase)** : Erase a matrix from the matrix array.
* **C (resize)** : Resize a matrix.
* **R (power)**: Calculate the power of a matrix in O(log n) time.
* **S (strassen multiply)** : Multiply two matrices using Strassen's algorithm.

## Functions

The program uses the following functions, which are defined in `functions.c`:

* **read_array** : Read and allocate memory for a 1D array.
* **alloc_matrix** : Allocate memory for a 2D matrix.
* **read_matrix**: Read and allocate memory for a matrix.
* **realloc_array** : Allocate or reallocate memory for a matrix array.
* **add_matrix** : Add a matrix to the matrix array.
* **load** : Read and load a matrix into the matrix array.
* **display_dimensions** : Display the dimensions of a matrix.
* **sum** : Calculate the sum of elements in a matrix.
* **sort_matrix_array** : Sort the matrix array based on the sum of elements.
* **print** : Print the elements of a matrix.
* **multiply** : Multiply two matrices.
* **free_matrix** : Free the memory allocated for a matrix.
* **free_all** : Free the memory allocated for the matrix array.
* **transpose_matrix** : Transpose a matrix.
* **erase_matrix** : Erase a matrix from the matrix array.
* **resize_matrix** : Resize a matrix.
* **calculate_aux_matrix** : Calculate the auxiliary matrix for power calculation.
* **power** : Calculate the power of a matrix.
* **strassen_multiply** : Multiply two matrices using Strassen's algorithm.

## Description

The program reads in a command and executes the corresponding function. It
uses a resizable matrix array to store matrices. I declared a constant 'MOD'
to be `10007` for avoiding overflow in all mathematical operations. 

The `load` function reads in a matrix and adds it to the matrix array, using the `read_matrix` function to read and allocate the matrix, the `realloc_array` function to allocate or reallocate memory for the matrix array, and the `add_matrix` function to add the matrix to the matrix array.
The `realloc_array` function allocates memory for the matrix array if it is empty, or reallocates memory for the matrix array if it is not empty, doubling the size of the matrix array. I also chose to allocate memory for a line array and a column array, which are used to store the number of lines and columns of each matrix in the matrix array.

The `display_dimensions` function simply prints the number of lines and columns of a matrix, after reading in the index of the matrix in the matrix array and checking if the index is valid, using the line and column arrays.

The `sort_matrix_array` function sorts the matrix array based on the sum of elements in each matrix, using the `sum` function to calculate the sum of elements in each matrix. I chose to use the quicksort algorithm to sort the matrix array.

The `print` function prints the elements of a matrix, after reading in the index of the matrix in the matrix array and checking if the index is valid, by simply looping through the given matrix.

The `multiply` function multiplies two matrices, after reading in the indices of the matrices in the matrix array and checking if the indices are valid. I first allocate memory for the result matrix, then loop through the two matrices to calculate the result matrix by multiplying the elements two by two. This is one of the functions where the `MOD` constant
comes in handy.

The `transpose_matrix` function transposes a matrix, after reading in the index of the matrix in the matrix array and checking if the index is valid. I first allocate memory for the result matrix, then loop through the given matrix to calculate the result matrix by transposing the elements. I then free the memory allocated for the given matrix and replace it with the result matrix, doing the same for the line and column arrays.

The `erase_matrix` function erases a matrix from the matrix array, after reading in the index of the matrix in the matrix array and checking if the index is valid. I first free the memory allocated for the given matrix, then loop through the matrix array to shift the matrices after the given matrix to the left by one position, doing the same for the line and column arrays. I also decrease the size of the matrix array by one, since one matrix has been erased.

The `resize_matrix` function resizes a matrix, after reading in the index of the matrix in the matrix array and checking if the index is valid. I first read in the new number of lines and columns, then allocate memory for the result matrix. I then loop through the given matrix to copy the elements to the result matrix, doing the same for the line and column arrays. I then free the memory allocated for the given matrix and replace it with the result matrix.

The `power` function calculates the power of a matrix in O(log n) time, after reading in the index of the matrix in the matrix array and checking if the index is valid. I first read in the power, then use the `calculate_aux_matrix` function to calculate the auxiliary matrix. The last thing I do is free the memory allocated for the given matrix and replace it with the result matrix, since the operation has to be done in place.
