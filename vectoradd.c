#include <stdio.h>
#include <stdlib.h>

void vector_add(float* a, float* b, float* c, int n){

    int i;
    for(i = 0; i < n; i++){
        c[i] = a[i] + b[i];
    }
}

int main(){

    int n;
    printf("Enter the size of the vector: ");
    scanf("%d", &n);

    float *a = (float *)malloc(n * sizeof(float));
    float *b = (float *)malloc(n * sizeof(float));
    float *c = (float *)malloc(n * sizeof(float));

    printf("Enter the elements of the first vector: ");

    for(int i = 0; i < n; i++){
        printf("Enter the element of a %d: ", i+1);
        scanf("%f", &a[i]);
    }

    printf("Enter the elements of the second vector: ");

    for(int i = 0; i < n; i++){
        printf("Enter the element of b %d: ", i+1);
        scanf("%f", &b[i]);
    }

    vector_add(a, b, c, n);

    printf("The resultant vector is: ");

    for(int i = 0; i < n; i++){
        printf("%f ", c[i]);
    }

    free(a);
    free(b);
    free(c);

    return 0;
}
