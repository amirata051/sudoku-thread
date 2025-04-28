Single-Threaded Sudoku Solver
This project contains a single-threaded Sudoku solver implemented in C. It can also be extended to support multi-threading using POSIX threads (pthreads).
Prerequisites

Ensure you have make and a C compiler (e.g., gcc) installed.
For multi-threading, you need libpthread installed on your system.

Running the Single-Threaded Version

Clone the repository:git clone https://github.com/amirata051/sudoku-thread.git
cd sudoku-thread


Build the project using the provided Makefile:make


Run the executable (replace <input_file> with a file from the input directory):./sudoku_single <input_file>

Example:./sudoku_single input/sample_input.txt



The program will solve the Sudoku puzzle and output the result (likely to a file in the out directory or to the terminal).
Adding Multi-Threading Support
To extend the solver to use multi-threading:

Add the multi-threaded validator files:

Add the files validator_pthread.c and validator_pthread.h to the src directory. These files implement the multi-threaded Sudoku validation logic.


Update the main file:

In main.c, replace the include statement for the single-threaded validator with the multi-threaded one:// Remove this:
#include "validator_single.h"
// Add this:
#include "validator_pthread.h"


Ensure the logic in main.c calls the appropriate multi-threaded validation functions.


Update the Makefile:

Modify the Makefile to compile validator_pthread.c instead of validator_single.c and link with the pthread library. Update the OBJS variable and add the -pthread flag:CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pthread
SRC = src
OBJS = $(SRC)/main.o $(SRC)/validator_pthread.o $(SRC)/io.o $(SRC)/test_runner.o
EXEC = sudoku_single

all: $(EXEC)

$(EXEC): $(OBJS)
    $(CC) $(CFLAGS) -o $@ $^

$(SRC)/%.o: $(SRC)/%.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(EXEC) $(SRC)/*.o




Build and run:

Rebuild the project:make


Run the multi-threaded version (replace <input_file> with a file from the input directory):./sudoku_single <input_file>

Example:./sudoku_single input/sample_input.txt





Notes

The single-threaded version is lightweight and suitable for smaller puzzles.
The multi-threaded version may improve performance for large or complex Sudoku puzzles by parallelizing validation tasks.
Ensure your system supports threading for the multi-threaded version.

