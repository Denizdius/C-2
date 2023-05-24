#include<stdio.h>
#include<stdlib.h>

double poly1(double x){
    return (x*x +2*x +2);
}

double poly2(double x){
    return (x*x +3*x );
}

int check_poly(double x ,double (*f)(double)){

    // herhangi bir fonskyionu pointer olarak kullanmak için yaptık kullanılacak fonskiyonun kaç inputa sahip olduğu önemli

    if(f(x)>x){
        return 1;
    }


    else {
          return 0;

    }

}


int main(){

    double x = 0;

    printf("%d\t",check_poly(x,poly1));
    printf("%d\t",check_poly(x,poly2));

    return 0;

}

    


