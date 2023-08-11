#include<stdio.h>
#include<stdlib.h>


 //then the function m_m is called with matrices A, B, and Multip and their dimensions as parameters.
 // The function uses three for loops to multiply the matrices according to the rules of matrix multiplication and stores the result in matrix Multip. 
 //The resulting matrix Multip is then printed using another nested for loop.
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



// The function first allocates memory to store a temporary matrix and uses t for loops to transpose the matrix A and store it in the temporary matrix. 
//The function then copies the elements of the temporary matrix back to matrix A and frees the memory allocated to the temporary matrix. 
//The resulting transposed matrix is printed using a for loop.
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


//the function m_a is called with matrices A, B, and Add and their just only one matrix's dimensions as parameters. 
//The function iterates over the elements of the matrices using for loops and adds the corresponding elements of matrices A and B and stores the result in matrix 
//Add. The resulting matrix Add is then printed using another nested for loop.

void m_a(int* A, int* B, int* matrix_Add, int rw, int cl) {
    int i, j;
    for (i = 0; i < rw; i++) {
        for (j = 0; j < cl; j++) {
            *(matrix_Add + i*cl + j) = *(A + i*cl + j) + *(B + i*cl + j);
        }
    }
}



//the function determinant is called with matrix A and its dimension as parameters. 
//The function calculates the determinant of matrix A using the rule of Sarrus if the matrix size is 3x3 or using the rule of expansion 
//if the matrix size is 2x2. The determinant is then returned and printed.
int determinant(int *matrix_A, int size) {

    int det = 0;
    if (size == 2) {
        det = matrix_A[0] * matrix_A[3] - matrix_A[1] * matrix_A[2];
    } else if (size == 3) {
        det = matrix_A[0] * (matrix_A[4] * matrix_A[8] - matrix_A[5] * matrix_A[7])
            - matrix_A[1] * (matrix_A[3] * matrix_A[8] - matrix_A[5] * matrix_A[6])
            + matrix_A[2] * (matrix_A[3] * matrix_A[7] - matrix_A[4] * matrix_A[6]);
    } else {
        printf("Error: Matrix size must be 2x2 or 3x3.\n");
        exit(1);
    }
    return det;
}




int main(void){

    int *matrix_A, *matrix_B, *matrix_Add,*matrix_Multip;
    int rw_a, cl_a;
    int rw_b,cl_b;
    int i, j;
    int det;
    int size;
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

    //The main function first takes the number of rows and columns of the matrices A and B as input from the user using the scanf . 
    //It then dynamically allocates memory to store matrices A, B, Add, and Multip using the malloc function.


    printf("\nEnter your choice press 1 for matrix addition\n");
    printf("\nEnter your choice press 2 for matrix  multiplication\n");
    printf("\nEnter your choice press 3 for matrix determinant\n");
    printf("\nEnter your choice press 4 for matrix transpose\n");
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

    if(cl_a == rw_a && rw_a == 2 ){

        size = 2;

        det  = determinant(matrix_A,size);
        printf("Determinant of matrix A = %d\n", det);
    }

    if(cl_a == rw_a && rw_a == 3 ){

        size = 3;

        det = determinant(matrix_A,size);
        printf("Determinant of matrix A = %d\n", det);
    }

    if(cl_b == rw_b && rw_b == 2 ){

        size = 2;

       det =  determinant(matrix_B,size);
        printf("Determinant of matrix B = %d\n", det);
    }

      if(cl_b == rw_b && rw_b == 3 ){

        size = 3;

       det = determinant(matrix_B,size);
        printf("Determinant of matrix B = %d\n", det);
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

 
