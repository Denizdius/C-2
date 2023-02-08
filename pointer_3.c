#include<stdio.h>
#include<stdlib.h>

int main (){

int *x1,*x2,*x3;

int n = 10; 
int p = 20;

 x1 = &n;
 x2 = &p;

 printf("\nBefore calculation\n");

 printf("\n%d\n",*x1);
 printf("%d\n",*x2);
 printf("adress of x1 %d\n",x1);

*x1 = *x2 +2;

printf("\nAfter new calculation\n");
printf("\nx1 %d\n",*x1);
printf("adres of x1 %d\n",x1);
printf("x2 %d\n",*x2);

return 0 ;

} 