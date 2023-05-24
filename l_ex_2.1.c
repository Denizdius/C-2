


#include <stdio.h>

#define N 3

void CreateIdentityMat(double *I) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                I[i*N+j] = 1.0;
            } else {
                I[i*N+j] = 0.0;
            }
        }
    }
}

double CalculateDeterminant(double *A) {
    double det = 0.0;
    det += A[0] * (A[4]*A[8] - A[5]*A[7]);
    det -= A[1] * (A[3]*A[8] - A[5]*A[6]);
    det += A[2] * (A[3]*A[7] - A[4]*A[6]);
    return det;
}

void CreateDxyz_mat(double *A, double *I, int A_colNum, double *Dxyz, int invA_colNum) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j == A_colNum) {
                Dxyz[i*N+j] = I[i*N+invA_colNum];
            } else {
                Dxyz[i*N+j] = A[i*N+j];
            }
        }
    }
}

void CramersRuleForInverse(double *A) {
    double detA = CalculateDeterminant(A);
    if (detA == 0.0) {
        printf("The matrix is singular, inverse does not exist.\n");
        return;
    }
    double Ainv[N*N];
    double I[N*N];
    CreateIdentityMat(I);
    for (int i = 0; i < N; i++) {
        double Dx[N*N], Dy[N*N], Dz[N*N];
        CreateDxyz_mat(A, I, i, Dx, 0);
        CreateDxyz_mat(A, I, i, Dy, 1);
        CreateDxyz_mat(A, I, i, Dz, 2);
        double detDx = CalculateDeterminant(Dx);
        double detDy = CalculateDeterminant(Dy);
        double detDz = CalculateDeterminant(Dz);
        Ainv[i*N+0] = detDx / detA;
        Ainv[i*N+1] = detDy / detA;
        Ainv[i*N+2] = detDz / detA;
    }
    printf("The inverse of the matrix is:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%f ", Ainv[i*N+j]);
        }
        printf("\n");
    }
}

int main() {
    double A[N*N];
    printf("Enter the elements of the matrix A:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%lf", &A[i*N+j]);
        }
    }
    CramersRuleForInverse(A);
    return 0;
}
