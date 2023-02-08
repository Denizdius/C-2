#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){

char deniz[100];
printf("Enter a word\n");
gets(deniz);


printf("\nSize of this array is %d\n",strlen(deniz));
printf("Size of this array %d\n",sizeof(deniz));

    return 0;
}