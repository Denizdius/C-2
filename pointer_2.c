#include<stdio.h>
#include<stdlib.h>

int main(){

int *p;
int n = 20;

p =&n;

printf("%d\n",*p );
printf("%d\n",p );
printf("%d\n",n ); 
printf("%d\n",&n );

//pointer aynı adreste farklı sayı atamaya sağlar 

*p = 30;// p değişti anda n sayısı da değişir ama adressi- 
//değişmez

printf("%d\n",n);
printf("%d\n",&n);




}