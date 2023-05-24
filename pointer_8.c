#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define Max 100

int main(){

    int l;
    int *p1;
    int arr[Max];
    int i;
    p1 = arr;

    printf("Enter a number limit of your array's number\n");
    scanf("%d",&l);

    for(i=0; i<l;i++){

        printf("\nEnter %d. member of array \n",i+1);
        scanf("%d",p1);
        p1++;


    }

    p1 = arr;


    for(i=0; i<l;i++){

        printf("\n %d. member of array's adress %d \n",i+1,p1);
        p1++;


    }

    p1 = arr;


    for(i=0; i<l;i++){

        printf("\n %d. member of array's value %d\n",i+1,*p1);
        p1++;


    }






    return 0;
}