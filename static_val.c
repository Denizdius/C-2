#include<stdio.h>
#include<stdlib.h>


int count_calls_static(){

    static int a=0;
    a++;
    return a;
}

int count_calls(){

    int a=0;
    a++;
    return a;
}




int main(){

printf("%d\t",count_calls_static());
printf("%d\t",count_calls_static());
printf("%d\t",count_calls_static());

//static değerler değerini korur fonksiyonla değişebilir ama değerleri resetlenmez.

printf("\n%d\t",count_calls());
printf("%d\t",count_calls());
printf("%d\t",count_calls());



return 0;
}