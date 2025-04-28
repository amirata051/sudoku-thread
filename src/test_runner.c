#include "test_runner.h"
#include "validator_single.h"
#include "io.h"
#include <stdio.h>
#include <time.h>

#define TEST_CASES 5

void run_tests() {
    char input_path[256], output_path[256];
    int sudoku[9][9];
    int passed = 0;
    double total_time = 0.0;

    for (int test = 1; test <= TEST_CASES; test++) {
        snprintf(input_path, sizeof(input_path), "input/input%d.txt", test);
        snprintf(output_path, sizeof(output_path), "output/output%d.txt", test);

        if (!read_input_file(input_path, sudoku)) {
            printf("❌ Test Case %d: Failed to read input file.\n", test);
            continue;
        }

        clock_t start = clock();
        bool actual_result = validate_sudoku(sudoku);
        clock_t end = clock();

        bool expected_result = read_expected_output(output_path);
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        total_time += time_taken;

        if (actual_result == expected_result) {
            printf("✅ Test Case %d Passed (Time: %.6f seconds)\n", test, time_taken);
            passed++;
        } else {
            printf("❌ Test Case %d Failed (Time: %.6f seconds) — Expected: %s, Got: %s\n",
                   test, time_taken,
                   expected_result ? "true" : "false",
                   actual_result ? "true" : "false");
        }
    }

    printf("\nSummary: %d/%d tests passed.\n", passed, TEST_CASES);
    printf("Total execution time (no threads): %.6f seconds\n", total_time);
}