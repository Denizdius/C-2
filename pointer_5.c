#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>
#define max 100



int main(){

char arr[max] ="deniz";
char *p1;

p1 = arr;

printf("5th chacarter is %c",arr[4]);

// ya da 

printf("\n5th chacarter is  %c\n",*(p1 + 4));

return 0;

}