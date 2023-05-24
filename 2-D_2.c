#include<stdio.h>
#include<stdlib.h>
#define M 100


int main(){


int n;
int i;
int j;
int mtx[M][M];
int imtx[M][M];
int smtx[M][M];

printf("\n Enter the sqr matrix n value \n");
scanf("%d",&n);

for (i=0;i<n;i++){

    for(j=0;j<n;j++){

        printf("\nEnter (%d ,%d) value of matrix \n",i ,j);
        scanf("%d",&mtx[i][j]);
    }

}

printf("\nValues of matrix is \n");

for (i=0;i<n;i++){

    for(j=0;j<n;j++){

        printf(" %d ",mtx[i][j]);

        if(j==n-1){
            printf("\n");
        }
    
    }

}


for (i=0;i<n;i++){

    for(j=0;j<n;j++){

        if(i==j){
            imtx[i][j] = 1;
        }

        else{
            imtx[i][j] = 0;
        }
    }

}


printf("\nValues of identity matrix is \n");

for (i=0;i<n;i++){

    for(j=0;j<n;j++){

        printf(" %d ",imtx[i][j]);

        if(j==n-1){
            printf("\n");
        }
    
    }

}

for (i=0;i<n;i++){

    for(j=0;j<n;j++){

        smtx[i][j] = imtx[i][j] + mtx[i][j];

    
    }

}


printf("\nValues of summation matrix is \n");

for (i=0;i<n;i++){

    for(j=0;j<n;j++){

        printf(" %d ",smtx[i][j]);

        if(j==n-1){
            printf("\n");
        }
    
    }

}






    return 0;
}