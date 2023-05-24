#include<stdio.h>
#include<stdlib.h>


int main(){

    int**p1;
    int i;
    int j;
    p1 = (int*)malloc(3*sizeof(int));

    for(i=0;i<3;i++){

        p1[i]=(int*)malloc(4*sizeof(int));

        for(j=0;j<4;j++){


            p1[i][j] = i*10 + j+1;
            printf("%3d",p1[i][j]);
        }

        printf("\n");


    }



    return 0;
}