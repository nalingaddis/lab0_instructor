# Lab 0 - Matrix Madness

COMP 530 Instructor's Guide

## Outline

* Project Layout
* Testing Harness
* Solution Guide

## Project Layout

In this assignment students will get practice working with different representations of memory in C, a fundamental skill for all future assignments. They are tasked with implemented four predefined functions that each compute the matrix product using a different form of memory in C. These tasks require the use both memory allocation and traversal, and furthermore provides them a great opportunity to practice command line debugging (another crucial skill for this course). An outline of the four exercises is as follows

1. Multiply two matrices as `double[][]` arrays and write the product into an array provided as a parameter. The main goal of this task is to test the student's mental model of matrix multiplication and does not require any new C memory skills. (i.e. they should be able to implement this function simply using `Java` like syntax).

2. Multiply two matrices as `double*` pointers and create a product `double*` to be return. This exercise introduces the students to the concept of pointers and basic memory traversal in C as well as dynamic memory allocation. Note that their algorithm code from `exercise1` should not change drastically, only their indexing needs to change from 2 dimensional to 1 dimensional (i.e. to index `[a][b]` we instead index `[a*C+b]` where `C` is the number of total columns).

3. Multiply two matrices as `double**` pointers and create a `double**` to be returned. This exercise introduces student to more complex double pointers, expanding on the mental model developed in the previous exercise. For this exercise, their algorithm code should be `yanked-and-pasted` exactly from `exercise1`.

4. Multiply two matrices as `Matrix` structs and create a `Matrix` struct to be returned. This exercise is conceptually the most challenging which is why to starter code outline is heavily commented with useful hints and steps. A `Matrix` struct is essential a linked list of `Row` structs, and each `Row` struct is a linked list of `Entry` structs. Thus it is much easier to traverse the matrix rows than columns and for this reason, the second input matrix is transposed to simplification the multiplication. After mastering this exercise students will have the C programming foundation needed to succeed in this course.

## Testing Harness

Provided to both the students and instructors is a testing files `tests.c` and a `Makefile` which generates an executable `tests` using the provided implementation of `MatrixMultiplier.c` and `tests.c`. Although this test file only tests on matrix multiplication operation, it provides all the functionality for converting a `double[][]` into `double*`, `double**`, and `Matrix` form making it extremely easy to expand this testing suite. In other words:

> Given matrices `M, N, P` as `double[][]` such that `M * N = P`, the testing suite will __automatically__ convert the matrices into `double*`, `double**` and `Matrix` form, and test the implementation of the functions provided in `MatrixMultiplier.c`. Note that for testing `exercise4` the suite will also transpose the second input matrix `double[][]` before converting it to a `Matrix`.

For further detail on testing harness, please see the comments in the `tests.c` file.

## Solution Guide

In this repository there is an implementation of the `MatrixMultiplier.c` file with the correct solutions to each implementation as well as heavily commented code describing each step of each exercise. For further detail on implementing a correct solution please consult this file.
