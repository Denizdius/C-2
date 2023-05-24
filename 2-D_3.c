#include<stdio.h>
#include<stdlib.h>


int main(){

int i;
int j;
int mtx[10][10];

for (i=0;i<10;i++){

    for(j=0;j<10;j++){

        mtx[i][j] = (i+1)*(j+1);
    }
}

printf("\nValues of multiplaction  table is \n");

for (i=0;i<10;i++){

     printf("-%d--",i+1);

    

    for(j=0;j<10;j++){

       

        printf(" %d ",mtx[i][j]);

        if(j==9){
            printf("\n");
        }
    
    }

}

return 0;


}