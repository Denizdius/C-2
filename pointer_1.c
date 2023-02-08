#include<stdio.h>
#include<stdlib.h>

int main(){

int n = 1;
int *p;

p =&n;

printf("%d\n",p);//adres için
printf("%d\n",*p);//değeri için


}