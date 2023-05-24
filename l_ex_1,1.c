#include <stdio.h>
#include <stdlib.h>


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

void m_m(int *A, int *B, int*D, int rows, int cols,int cols_1) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols_1; j++) {
            int sum = 0;
            for (int k = 0; k < cols; k++) {
                sum += *(A + i*cols + k) * *(B + k*cols_1 + j);
            }
            *(D + i*cols_1 + j) = sum;
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

int main(void){



    int rows, cols;
    int rows_1,cols_1;
    int *A, *B, *C,*D;
    int i, j;

    printf("Enter number of rows A: ");
    scanf("%d", &rows);
    printf("Enter number of columns A: ");
    scanf("%d", &cols);

    printf("Enter number of rows B: ");
    scanf("%d", &rows_1);
    printf("Enter number of columns B: ");
    scanf("%d", &cols_1);


   
    A = (int*)malloc(rows * cols * sizeof(int));
    B = (int*)malloc(rows_1 * cols_1 * sizeof(int));
    C = (int*)malloc(rows * cols * sizeof(int));
    D = (int*)malloc(rows * cols_1 * sizeof(int));

    
    printf("Enter elements of matrix A:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", A + i*cols_1 + j);
        }
    }

    
    printf("Enter elements of matrix B:\n");
    for (i = 0; i < rows_1; i++) {
        for (j = 0; j < cols_1; j++) {
            scanf("%d", B + i*cols_1 + j);
        }
    }

    printf("\nResult  of addition \n");

    

    if( rows_1 == rows && cols == cols_1){


    m_a(A, B, C, rows, cols);

    // print the resulting matrix C
    printf("Result matrix C:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", *(C + i*cols + j));
        }
        printf("\n");
    
    }

    }

     else {

        printf("\nAddition cant be done\n");
    }
    

    printf("\n Results of matrices multipcation\n");

    if( cols == rows_1){

        m_m(A, B, D, rows, cols,cols_1);

   
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols_1; j++) {
            printf("%d ", *(D + i*cols_1 + j));
        }
        printf("\n");
    }




    }


     else{
        printf("\nMultiplacation cant be done\n");
    }



    

    if (m_s(A, rows)) {
        printf("The A matrix is symmetric.\n");
    } else {
        printf("The A matrix is not symmetric.\n");
    }

    if (m_s(B, rows_1)) {
        printf("The B matrix is symmetric.\n");
    } else {
        printf("The B matrix is not symmetric.\n");
    }


    printf("\n Transpose of A matrix");

    m_t(A, rows, cols);

    printf("\tTransposed matrix:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", A[i * rows + j]);
        }
        printf("\n");
    }


     printf("\n Transpose of B matrix");

    m_t(B, rows_1, cols_1);

    printf("\tTransposed matrix:\n");
    for (int i = 0; i < cols_1; i++) {
        for (int j = 0; j < rows_1; j++) {
            printf("%d ", B[i * rows_1 + j]);
        }
        printf("\n");
    }

    // free dynamically allocated memory
    free(A);
    free(B);
    free(C);
    free(D);

    return (0);


}

 
