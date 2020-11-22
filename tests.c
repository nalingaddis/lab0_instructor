#include "MatrixMultiplier.h"

// The dimension of the input array 
const int A = 6, B = 5, C = 9;

// The first input matrix
const double M[A][B] = {
    {1 ,5 ,7 ,0 ,8},
    {7 ,2 ,6 ,4 ,2},
    {8 ,5 ,2 ,3 ,7},
    {6 ,2 ,7 ,7 ,4},
    {4 ,6 ,2 ,2 ,1},
    {4 ,2 ,3 ,8 ,4}
};

// The second input matrix
const double N[B][C] = {
    {1 ,0 ,4 ,1 ,9 ,7 ,2 ,2 ,2},
    {7 ,1 ,0 ,7 ,2 ,1 ,1 ,7 ,3},
    {4 ,3 ,8 ,0 ,4 ,4 ,0 ,8 ,8},
    {0 ,3 ,6 ,8 ,9 ,7 ,2 ,1 ,7},
    {5 ,3 ,0 ,1 ,7 ,4 ,2 ,4 ,2}
};

// The expected product of M * N
const double P[A][C] = {
    {104, 50, 60, 44, 103, 72, 23, 125, 89}, 
    {55, 38, 100, 55, 141, 111, 28, 88, 100}, 
    {86, 41, 66, 74, 166, 118, 41, 98, 82}, 
    {68, 56, 122, 80, 177, 137, 36, 105, 131}, 
    {59, 21, 44, 63, 81, 60, 20, 72, 58}, 
    {50, 47, 88, 86, 152, 114, 34, 70, 102}
};

/* ------------- DO NOT EDIT CODE BELOW -------------*/

// Give a test function, f, execute the test and print the result
void test(int (*f)(), char* name) {
    if(f()) printf("Exercise %s failed\n", name);
    else printf("Exercise %s passed\n", name);
}

// Test exercise 1
int test1() {
    double output[A][C];

    exercise1(M,N,output);

    for(int r=0; r<A; r++) {
        for(int c=0; c<C; c++) {
            if(output[r][c]!=P[r][c]) {
                return 1;
            }
        }
    }

    return 0;
}

// Test exercise 2
int test2() {
    double* actual = exercise2(&M[0][0], &N[0][0]);

    if(!actual) return 1;

    const double* expected = &P[0][0];

    for(int i=0; i<A*C; i++) {
        if(actual[i]!=expected[i]) {
            return 1;
        }
    }

    return 0;
}

// Test exercise 3
int test3() {

    const double** m = (const double**) malloc(sizeof(double*) * A);
    const double** n = (const double**) malloc(sizeof(double*) * B);
    
    for(int r=0; r<A; r++) m[r] = &M[r][0];
    for(int r=0; r<B; r++) n[r] = &N[r][0];

    const double** expected = (const double**) malloc(sizeof(double*) * A);
    for(int r=0; r<A; r++) expected[r] = &P[r][0];

    double** actual = exercise3(m, n);
    if(!actual) return 1;

    for(int r=0; r<A; r++) {
        for(int c=0; c<C; c++) {
            if(actual[r][c]!=expected[r][c]) {
                return 1;
            }
        }
    }

    return 0;
}

// Given an array return it as a matrix
Matrix* ArrayToMatrix(const double* M, const int R, const int C) {
    Matrix* m = (Matrix*) malloc(sizeof(Matrix));
    Row* row = (Row*) malloc(sizeof(Row));
    m->rowList = row;

    Entry* entry;
    for(int r=0; r<R; r++) {
        entry = (Entry*) malloc(sizeof(Entry));
        row->entryList = entry;
        for(int c=0; c<C; c++) {
            entry->value = M[r*C+c];
            entry->next = (Entry*) malloc(sizeof(Entry));
            entry = entry->next;
        }
        row->next = (Row*) malloc(sizeof(Row));
        row = row->next;
    }

    return m;
}

// Transpose a matrix
double* transpose(const double* M, const int R, const int C) {
    double* T = (double*) malloc(sizeof(double) * R * C);

    for(int r=0; r<R; r++) {
        for(int c=0; c<C; c++) {
            T[c*R+r] = M[r*C+c]; 
        }
    }

    return T;
}

// Test exercise 4
int test4() {
    Matrix* expected = ArrayToMatrix(&P[0][0], A, C);
    
    Matrix* actual = 
        exercise4(
            ArrayToMatrix(&M[0][0], A, B), 
            ArrayToMatrix(transpose(&N[0][0],B,C), C, B));
    if(!actual) return 1;

    Row* actualRow = actual->rowList;
    Row* expectedRow = expected->rowList;

    Entry* actualEntry;
    Entry* expectedEntry;

    for(int r=0; r<A; r++) {
        actualEntry = actualRow->entryList;
        expectedEntry = expectedRow->entryList; 

        for(int c=0; c<C; c++) {
            if(actualEntry->value != expectedEntry->value) {
                return 1;
            }
            actualEntry = actualEntry->next;
            expectedEntry = expectedEntry->next;
        }

        actualRow = actualRow->next;
        expectedRow = expectedRow->next;
    }

    return 0;
}

// Execute tests
int main() {
    test(test1, "1");
    test(test2, "2");
    test(test3, "3");
    test(test4, "4");
}