#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define max 100

int main(){

int arr[max]  = {8,1,2003};
int *p1;
p1 = arr;

printf("\nadres of 1st integer %d \n",p1);
printf("\nadress of 2nd integer %d \n",(p1+1));
printf("\n value of 2nd integer %d \n",*(p1+1));
//int olduğu için adrelsler 4 'er bit artar 


    return 0;
}
