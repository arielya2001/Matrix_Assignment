# Matrix Assignment - SquareMat
# Mail - ariel.yaacobi@msmail.ariel.ac.il

## Overview
This project implements a square matrix class (`SquareMat`) in C++. It supports a wide variety of operations on square matrices such as addition, subtraction, multiplication (both scalar and matrix), modulo operations, determinant calculation, transposition, and comparisons. The project includes:
- A `SquareMat` class definition (`SquareMat.h` and `SquareMat.cpp`)
- A test suite using the `doctest` framework (`testSquareMat.cpp`)
- A demonstration of matrix operations in a main program (`Main.cpp`)
- A Makefile to compile and run the project, including memory checks using `valgrind`

## File Structure
- `SquareMat.h`: Header file defining the `SquareMat` class and its interface.
- `SquareMat.cpp`: Implementation of the `SquareMat` class and its operators.
- `Main.cpp`: A simple main file demonstrating the various operations.
- `testSquareMat.cpp`: A comprehensive set of tests written using the `doctest` framework.
- `Makefile`: Used to compile the project (`make`), run tests (`make test`), and check for memory leaks (`make valgrind`).

## Class Design

### SquareMat
- Represents an `n x n` matrix using a dynamic 2D array (`double** data`).
- Validates matrix dimensions and memory allocations.
- Supports various operators: arithmetic, element-wise, comparison, unary, and custom operations like transpose and determinant.
- Uses a nested `RowProxy` class to ensure safe access to matrix elements with bounds checking on both rows and columns.

### RowProxy (Inner Class)
- Facilitates safe double-index access `m[i][j]` with full bounds checking.
- Ensures both const and non-const access via overloaded `operator[]`.

## Features
- Fully dynamic memory management.
- Deep copy support via copy constructor and assignment operator.
- All memory allocations are tested for leaks using `valgrind`.
- Exception-safe: throws appropriate exceptions (`std::invalid_argument`, `std::out_of_range`) on invalid operations.

## Usage
Build and run the project with:
```
make
./Main
```

Run the test suite with:
```
make test
```

Run memory checks with:
```
make valgrind
```
Clean the project with:
```
make clean
```

## Notes
- All matrices must be square (`n x n`).
- Division and modulo by zero are explicitly checked and throw exceptions.
- Comparison between matrices is based on the sum of their elements (as specified).

## Author & Date
- Developed by: Ariel Ya'acobi
- Assignment: Matrix Assignment - SquareMat
- Date: April 2025
