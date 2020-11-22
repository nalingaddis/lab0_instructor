#include <stdlib.h>
#include <stdio.h>

#ifndef MM_HEADER
#define MM_HEADER

/** 
 * The matrix dimensions being multiplied
 * Defined in the tests.c file
 */
extern const int A, B, C;

/** Computes the matrix product of M * N and store it in P
 * @param M A x B matrix
 * @param N B x C matrix
 * @param P A x C matrix
 */
void exercise1(const double M[A][B], const double N[B][C], double P[A][C]);

/** Computes the matrix produce of M * N
 * @param M A pointer to a A x B matrix stored in row major order
 * @param N A pointer to a B x C matrix stored in row major order
 * @returns A pointer to the matrix product of M * N stored in row major order
 */
double* exercise2(const double* M, const double* N);

/** Computes the matrix product of M * N
 * @param M A double pointer to a A x B matrix (row major order)
 * @param N A double pointer to a B x C matrix (row major order)
 * @return A double pointer to the matrix product of M * N
 */
double** exercise3(const double** M, const double** N);

/** 
 * Represents a single Matrix entry
 * Acts like a linked list node in a Row of entries 
 */
typedef struct Entry Entry;

/** 
 * Represents a single Matrix entry
 * Acts like a linked list node in a list of Rows
 * Stores a linked list of entries 
 * */
typedef struct Row Row;

/** 
 * Represents a matrix
 * Stores a linked list of rows 
 */
typedef struct Matrix Matrix;

struct Entry {
    // The value at this entry
    double value;
    // The next entry in the row
    Entry* next;
};

struct Row {
    // The head of the entry linked list
    struct Entry* entryList;
    // The next row in the matrix
    Row* next;
};

struct Matrix {
    // The head of the row linked list
    Row* rowList;
};

/** Multiplies M by the transpose of A and returns the product
 * @param M A A x B matrix struct
 * @param N A C X B matrix struct
 * @return The A x C matrix struct representing the matrix product of M * N
 */
Matrix* exercise4(const Matrix* M, const Matrix* N);

#endif