#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>



void change(int *x1,int *x2){

    int temp;

    temp = *x1;
    *x1 = *x2;
    *x2 = temp;

    //pointer kulanmazsan global olarak değiştiremezsin


}

int main(){

int a;
int b;

printf("\nENTER val_1\n");
scanf("%d",&a);
printf("\nval_1 : %d ",a);
printf("\n");

printf("\n ENTER val_2\n");
scanf("%d",&b);
printf("\n");
printf("\nval_2 : %d ",b);

change(&a,&b);
printf("\n");
printf("\n after change val_1 : %d ",a);
printf("\n after change val_2 : %d ",b);

    return 0;
}