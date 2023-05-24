#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
grgtg

*/
            

*

// Function to create a 3x3 identity matrix
void create_identity_matrix(float matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
}

// Function to calculate the determinant of a 3x3 matrix
float determinant(float matrix[3][3]) {
    float det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
                matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
                matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    return det;
}

// Function to create Dxyz matrices
void create_dxyz_mat(float matrix[3][3], float dxyz_mat[3][3], int col, float value) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            dxyz_mat[i][j] = (j == col) ? value : matrix[i][j];
        }
    }
}

// Function to find the inverse of a 3x3 matrix using Cramer's Rule
void inverse_cramers_rule(float matrix[3][3], float inverse[3][3]) {
    float det = determinant(matrix);
    if (det == 0) {
        printf("The matrix is singular and has no inverse.\n");
        return;
    }

    float dxyz_mat[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            create_dxyz_mat(matrix, dxyz_mat, j, matrix[i][j]);
            inverse[j][i] = determinant(dxyz_mat) / det;
        }
    }
}

int main() {
    float matrix[3][3];
    float inverse[3][3];

    // Ask for the elements of matrix A
    printf("Enter the elements of the 3x3 matrix A:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    // Calculate the inverse using Cramer's Rule
    inverse_cramers_rule(matrix, inverse);

    // Print the inverse matrix
    printf("The inverse of the matrix A is:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2f ", inverse[i][j]);
        }
        printf("\n");
    }

    return 0;
}
