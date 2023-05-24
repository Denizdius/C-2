#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define Max 100

int main(){

    int l;
    int *p1;
    int arr[Max];
    int arr_2[Max];//yeni dizim
    int i;
    int *p2;
    p1 = arr;
    

    printf("Enter a number limit of your array's number\n");
    scanf("%d",&l);

    for(i=0; i<l;i++){

        printf("\nEnter %d. member of array \n",i+1);
        scanf("%d",p1);
        p1++;


    }

    p1 = arr;
    
    p2 = arr_2;

    for(i=0;i<l;i++){
        arr_2[i] = *p1;
        p1++;
    }

    p1 = arr;

    for(i=0; i<l;i++){

        printf("\n first array numbers %d. member of array's value %d\n",i+1,*p1);
        p1++;


    } 


    for(i=0; i<l;i++){

        printf("\n second arrays numbers %d. member of array's value %d\n",i+1,*p2);
        p2++;


    }

    arr_2[l-1] = 3;
    printf("\n changed crew of array_2 is %d",arr_2[l-1]);
    printf("\n unchanged crew of array_1 is %d",arr[l-1]);


    return 0;
}