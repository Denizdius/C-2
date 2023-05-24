#include<stdio.h>
#include<stdlib.h>
#define Max 100


int max (int arr[],int n){

    int max = arr[0];
    int i;

    for(i=0;i<n;i++){
        if(arr[i]>max){

            max = arr[i];

        }
    }

    return max;


}






int min (int arr[],int n){

    int min = arr[0];
    int i;
    
    for(i=0;i<n;i++){
        if(arr[i]<min){

            min = arr[i];

        }
    }

    return min;
}









int main(){


int i;
int arr[Max];
int *p1;
int ma;
int mi;

p1 = arr;

for(i=0;i<10;i++){

     printf("\n Enter the %d. member of this array \n",i+1);
     scanf("%d",p1);
     p1++;
}


ma = max(arr,10);
mi = min(arr,10);

printf("\n Max value of this array %d and Min value of this array %d\n",ma,mi);




return 0;

}