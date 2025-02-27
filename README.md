# My Octave - Matrix Operations in C  

## Overview  
My Octave is a C program that allows users to perform various matrix operations efficiently. It supports loading, printing, resizing, transposing, multiplying, sorting, and raising matrices to a power. The program is designed for interactive use through command-line inputs.

## Features  
- Load and store multiple matrices dynamically  
- Display matrix dimensions  
- Print matrices in a structured format  
- Resize matrices by selecting specific rows and columns  
- Multiply matrices using both standard and Strassen’s algorithm  
- Sort matrices based on the sum of their elements  
- Transpose matrices  
- Compute matrix exponentiation in **O(log n)** time  
- Delete matrices from memory  
- Efficient memory management  

## Project Structure  
MyOctave/
│── my_octave.c # Main program handling user commands
│── functions.c # Implementation of matrix operations
│── functions.h # Function prototypes
│── Makefile # Build automation script

## Example Commands
Once the program starts, enter commands to manipulate matrices:

L       # Load a new matrix  
D 0     # Display dimensions of matrix 0  
P 0     # Print matrix 0  
M 0 1   # Multiply matrix 0 and matrix 1  
T 0     # Transpose matrix 0  
F 1     # Delete matrix 1  
Q       # Quit the program  

## Commands Reference  

| Command | Description |
|---------|------------|
| `L`     | Load a new matrix |
| `D i`   | Display dimensions of matrix `i` |
| `P i`   | Print matrix `i` |
| `C i`   | Resize matrix `i` |
| `M i j` | Multiply matrices `i` and `j` |
| `O`     | Sort matrices based on sum of elements |
| `T i`   | Transpose matrix `i` |
| `R i n` | Raise matrix `i` to the power of `n` |
| `F i`   | Delete matrix `i` |
| `S i j` | Multiply matrices `i` and `j` using Strassen's algorithm |
| `Q`     | Quit the program and free memory |
