#include "io.h"
#include <string.h>

bool read_input_file(const char* filename, int sudoku[9][9]) {
    FILE* file = fopen(filename, "r");
    if (!file) return false;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (fscanf(file, "%d", &sudoku[i][j]) != 1) {
                fclose(file);
                return false;
            }
        }
    }
    fclose(file);
    return true;
}

bool read_expected_output(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) return false;
    char result[10];
    fscanf(file, "%s", result);
    fclose(file);
    return strcmp(result, "true") == 0;
}
