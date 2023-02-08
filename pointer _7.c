#include<stdio.h>
#include<stdlib.h>
#define MAX 100


int main(){

int  arr[MAX];

int *p1;


for(p1 = arr ;p1<arr+100; p1 = p1 + 1){

    *p1 =0;
}


for(p1 = arr ;p1<arr+100; p1 = p1 + 1){

    printf("%d\n",*p1);
}

return 0;

}