#include "MatrixMultiplier.h"

// Compute the matrix product M * N and store it in P
void exercise1(const double M[A][B], const double N[B][C], double P[A][C]) {
    // Syntatically this should look similar to Java
    
    // Hints:
    // - See the assignment write up for the defintion of a matrix product
    // - Remember to initialize the values of P before using them
    for(int r=0; r<A; r++) {
        for(int c=0; c<C; c++) {
            P[r][c] = 0;
            for(int i=0; i<B; i++) {
                P[r][c] += M[r][i] * N[i][c];
            }
        }
    }
}

// Compute M * N using pointers and return the product as a pointer
double* exercise2(const double* M, const double* N) {
    // Initialize a chuck of memory on the heap big enough for the product

    // Hints: 
    // - Use malloc to allocate heap memory
    // - Use `sizeof(type)` to get the size required to represent a single instance of `type`
    // - Remember to cast the result of malloc to the appropiate pointer type 
    double* P = (double*) malloc(sizeof(double) * A * C);
    
    // Loop through the values of M, N to compute the product

    // Hints:
    // - Remember to initialize the values in your heap memory before use
    // - Remember you can only index like a 1D array, indices need to be expressions
    for(int r=0; r<A; r++) {
        for(int c=0; c<C; c++) {
            P[r*C+c] = 0;
            for(int i=0; i<B; i++) {
                P[r*C+c] += M[r*B+i] * N[i*C+c];
            }
        }
    }

    // Return the matrix product
    return P;
}

// Compute M * N using double pointers and return the product as a double pointer 
double** exercise3(const double** M, const double** N) {
    // Allocate a a chuck of memory to return, each value in the chuck will be 
    // a single pointer that points to a row of the matrix
    double** P = (double**) malloc(sizeof(double*) * A);

    // For each pointer in your chuck of memory, allocate another chuck of memory
    // to hold the values of the row represented by this pointer
    for(int i=0; i<A; i++) P[i] = (double*) malloc(sizeof(double) * C);

    // Loop through the input pointers and compute the product
    // Note that although double pointers maybe conceptually more confusing,
    // using them in this context is more familiar because we can index them
    // like how we would index a 2D array

    // Hints:
    // - This part should look EXTREMELY similar to exercise 1
    // - Again remember to initial all values in memory before use
    for(int r=0; r<A; r++) {
        for(int c=0; c<C; c++) {
            P[r][c] = 0;
            for(int i=0; i<B; i++) {
                P[r][c] += M[r][i] * N[i][c];
            }
        }
    }

    // Return the product
    return P; 
}

// Compute the product of M and the TRANSPOSE of N using structs
// Before implementing this exercise please do the following:
// - Read the assignment right up for a refresher on matrix transposes
// - Inspect struct implementations in the MatrixMultiplication.h file 
// - For further reading on the Matrix implementation used here, see assignment write up
Matrix* exercise4(const Matrix* M, const Matrix* N) {
    // Initialize a new Matrix pointer
    // Hint: To initialize a pointer generally (and in the context of this assignmet) means 
    // to declare it and then assign it a value returned by malloc
    Matrix *P = (Matrix*) malloc(sizeof(Matrix));

    // Initialize a new Row pointer, this row will be the head of the row linked list
    Row *PRow = (Row*) malloc(sizeof(Row));

    // Store the address of this row in your Matrix pointer
    // Hint: Use the '->' operator to access values inside a struct pointer
    P->rowList = PRow;
    
    Row *MRow = M->rowList, *NCol;
    Entry *MEntry, *NEntry, *PEntry;

    // Begin looping through the input matrices
    for(int r=0; r<A; r++) {
        // Steps to complete here:
        // - Get the first entry of the current row of M
        // - Get the first row of N
        // - Initialize a new entry and store it as the head of the current row of P

        MEntry = MRow->entryList;
        NCol = N->rowList;

        PEntry = (Entry*) malloc(sizeof(Entry));
        PRow->entryList = PEntry;

        for(int c=0; c<C; c++) {
            // Steps to complete here:
            // - Get the first entry in the current row of N
            // - Initialize the value of the current entry of P

            NEntry = NCol->entryList;

            PEntry->value = 0;

            for(int i=0; i<B; i++) {
                // Steps to complete here:
                // - Update the value of the current entry of P
                // - Increment the current entry of M
                // - Increment the current entry of N

                PEntry->value += MEntry->value * NEntry->value;
                
                MEntry = MEntry->next;
                NEntry = NEntry->next;
            }
            // Steps to complete here:
            // - Initialize the next entry of P
            // - Increment the current entry of P
            // - Increment the current row of N
            // - Reset the current entry of M to head of the current row of M
            PEntry->next = (Entry*) malloc(sizeof(Entry));
            PEntry = PEntry->next;

            NCol = NCol->next;
            MEntry = MRow->entryList;
        }
        // Steps to complete here:
        // - Initialize the next row of P
        // - Increment the current row of P
        // - Increment the current row of M
        PRow->next = (Row*) malloc(sizeof(Row));
        PRow = PRow->next;
        MRow = MRow->next;
    }
    
    // Return the product
    return P;
}