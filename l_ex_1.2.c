#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>




void m_m(int *A, int *B, int*matrix_Multip, int rw, int cl,int cl_b) {
    for (int i = 0; i < rw; i++) {
        for (int j = 0; j < cl_b; j++) {
            int sum = 0;
            for (int k = 0; k < cl; k++) {
                sum += *(A + i*cl + k) * *(B + k*cl_b + j);
            }
            *(matrix_Multip + i*cl_b + j) = sum;
        }
    }
}


void m_t(int *A, int rw, int cl) {
    int *tmp = malloc(rw * cl * sizeof(int));
    for (int i = 0; i < rw; i++) {
        for (int j = 0; j < cl; j++) {
            tmp[j * rw + i] = A[i * cl + j];
        }
    }
    for (int i = 0; i < cl * rw; i++) {
        A[i] = tmp[i];
    }
    free(tmp);
}



void m_a(int* A, int* B, int* matrix_Add, int rw, int cl) {
    int i, j;
    for (i = 0; i < rw; i++) {
        for (j = 0; j < cl; j++) {
            *(matrix_Add + i*cl + j) = *(A + i*cl + j) + *(B + i*cl + j);
        }
    }
}

int m_s(int*A, int rw) {
    for (int i = 0; i < rw; i++) {
        for (int j = 0; j < rw; j++) {
            if (*(A + i*rw + j) != *(A+ j*rw + i)) {
                return 0;
            }
        }
    }
    return 1;
}

int main(void){

    int *matrix_A, *matrix_B, *matrix_Add,*matrix_Multip;
    int rw_a, cl_a;
    int rw_b,cl_b;
    int i, j;
    int choice;

    printf("Enter number of rows of A matrix : ");
    scanf("%d", &rw_a);
    printf("Enter number of columns of A matrix: ");
    scanf("%d", &cl_a);

    printf("Enter number of rows of B matrix : ");
    scanf("%d", &rw_b);
    printf("Enter number of columns of B matrix : ");
    scanf("%d", &cl_b);


   
    matrix_A = (int*)malloc(rw_a * cl_a * sizeof(int));
    matrix_B = (int*)malloc(rw_b * cl_b * sizeof(int));
    matrix_Add = (int*)malloc(rw_a * cl_a * sizeof(int));
    matrix_Multip = (int*)malloc(rw_a * cl_b * sizeof(int));

   


    
    printf("Enter elements of matrix A:\n");
    for (i = 0; i < rw_a; i++) {
        for (j = 0; j < cl_a; j++) {
            scanf("%d", matrix_A + i*cl_b + j);
        }
    }

    
    printf("Enter elements of matrix B:\n");
    for (i = 0; i < rw_b; i++) {
        for (j = 0; j < cl_b; j++) {
            scanf("%d", matrix_B + i*cl_b + j);
        }
    }


    printf("\nEnter your choice press 1 for matrix addition\n");
    printf("\nEnter your choice press 2 for matrix  multiplication\n");
    printf("\nEnter your choice press 3 for matrix transpose\n");
    printf("\nEnter your choice press 4 for matrix symetry\n");
    scanf("%d",&choice);

    switch(choice){

    case 1:

    printf("\nResult  of addition \n");


    if( rw_b == rw_a && cl_a == cl_b){


    m_a(matrix_A, matrix_B, matrix_Add, rw_a, cl_a);

    // print the resulting matrix C
    printf("Result of addition in addition matrix Add:\n");
    for (i = 0; i < rw_a; i++) {
        for (j = 0; j < cl_a; j++) {
            printf("%d ", *(matrix_Add + i*cl_a + j));
        }
        printf("\n");
    
    }

    }

     else {

        printf("\nAddition cant be done\n");
    }

    break;

    case 2:

    printf("\n Results of matrices multipcation\n");

    if( cl_a == rw_b){

        m_m(matrix_A, matrix_B, matrix_Multip, rw_a, cl_a,cl_b);

   
    for (int i = 0; i < rw_a; i++) {
        for (int j = 0; j < cl_b; j++) {
            printf("%d ", *(matrix_Multip + i*cl_b + j));
        }
        printf("\n");
    }




    }


     else{
        printf("\nMultiplacation cant be done\n");
    }

    break;

    case 3:


    if (m_s(matrix_A, rw_a)) {
        printf("The A matrix is symmetric.\n");
    } else {
        printf("The A matrix is not symmetric.\n");
    }

    if (m_s(matrix_B, rw_b)) {
        printf("The B matrix is symmetric.\n");
    } else {
        printf("The B matrix is not symmetric.\n");
    }
    break;

    case 4:


    printf("\n Transpose of A matrix");

    m_t(matrix_A, rw_a, cl_a);

    printf("\tTransposed matrix:\n");
    for (int i = 0; i < cl_a; i++) {
        for (int j = 0; j < rw_a; j++) {
            printf("%d ", matrix_A[i * rw_a + j]);
        }
        printf("\n");
    }


     printf("\n Transpose of B matrix");

    m_t(matrix_B, rw_b, cl_b);

    printf("\tTransposed matrix:\n");
    for (int i = 0; i < cl_b; i++) {
        for (int j = 0; j < rw_b; j++) {
            printf("%d ", matrix_B[i * rw_b + j]);
        }
        printf("\n");
    }

    break;

    }

    free(matrix_A);
    free(matrix_B);
    free(matrix_Add);
    free(matrix_Multip);

    return (0);


}

 
