#include <stdio.h>
#include <stdlib.h>

// function to add two matrices and store the result in C
void m_a(int* A, int* B, int* C, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            *(C + i*cols + j) = *(A + i*cols + j) + *(B + i*cols + j);
        }
    }
}

void m_t(int *A, int rows, int cols) {
    int *tmp = malloc(rows * cols * sizeof(int));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            tmp[j * rows + i] = A[i * cols + j];
        }
    }
    for (int i = 0; i < cols * rows; i++) {
        A[i] = tmp[i];
    }
    free(tmp);
}

void matrix_multiply(int *A, int *B, int*D, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int sum = 0;
            for (int k = 0; k < cols; k++) {
                sum += *(A + i*cols + k) * *(B + k*rows + j);
            }
            *(D + i*rows + j) = sum;
        }
    }
}

int m_s(int*A, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            if (*(A + i*rows + j) != *(A+ j*rows + i)) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int rows, cols;
    int *A, *B, *C,*D;
    int i, j;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // dynamically allocate memory for matrices A, B, and C
    A = (int*)malloc(rows * cols * sizeof(int));
    B = (int*)malloc(rows * cols * sizeof(int));
    C = (int*)malloc(rows * cols * sizeof(int));
    D = (int*)malloc(rows * cols * sizeof(int));

    // get input for matrix A
    printf("Enter elements of matrix A:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", A + i*cols + j);
        }
    }

    // get input for matrix B
    printf("Enter elements of matrix B:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", B + i*cols + j);
        }
    }

    printf("\nResult  of addition \n");

    // call matrix_addition function to add matrices A and B and store the result in C
    m_a(A, B, C, rows, cols);

    // print the resulting matrix C
    printf("Result matrix C:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", *(C + i*cols + j));
        }
        printf("\n");
    
    }

    printf("\n Results of matrices multipcation\n");



    matrix_multiply(A, B, D, rows, cols);

    // Print matrix c (the result)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(D + i*cols + j));
        }
        printf("\n");
    }

    if (m_s(A, rows)) {
        printf("The A matrix is symmetric.\n");
    } else {
        printf("The A matrix is not symmetric.\n");
    }

    if (m_s(B, rows)) {
        printf("The Bmatrix is symmetric.\n");
    } else {
        printf("The B matrix is not symmetric.\n");
    }


    printf("\n Transpose of A matrix\n");

    m_t(A, rows, cols);

    printf("\tTransposed matrix:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", A[i * rows + j]);
        }
        printf("\n");
    }


     printf("\n Transpose of B matrix");

    m_t(B, rows, cols);

    printf("\tTransposed matrix:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", B[i * rows + j]);
        }
        printf("\n");
    }

    // free dynamically allocated memory
    free(A);
    free(B);
    free(C);
    free(D);

    return 0;
}
