#ifndef IO_H
#define IO_H

#include <stdbool.h>
#include <stdio.h>

bool read_input_file(const char* filename, int sudoku[9][9]);
bool read_expected_output(const char* filename);

#endif