#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<malloc.h>


/*double *multi_output(double a){
    static double out[3];
    out[0] = sqrt(a);
    out[1] = a*a;
    out[2] = a*a*a;

    return out;

}

// math için cpp uzantısını kulansan daha iyi olur.
// static valuler memory efficent değildir


int main(){

double*x = multi_output(3);

printf("%f\t%f\t%f\t",x[0],x[1],x[2]);


    return 0;


}

-

double *multi_output(double a,double *x,double *y,double *z){

    *x= sqrt(a);
    *y = a*a;
    *z = a*a*a;
}

pointer methodu 3 den fazla inputlarda sıkıntı yaratabilir


int main(){

    double x,y,z;
    multi_output(3,&x,&y,&z);
    printf("%f\t%f\t%f\t",x,y,z);

    return 0;


}







void multiple_outputs(double a, double x[]){

    x[0] = sqrt(a);
    x[1] = a*a;
    x[2] = a*a*a;
 
}

int main(){

    double x[3];
    multiple_outputs(3,x);
    printf("%f\t%f\t%f\t",x[0],x[1],x[2]);
    return 0;
  
}

*/

double * multiple_outputs(double a){

    double *out = (double*)malloc (sizeof(double)*3);

    out[0] = sqrt(a);
    out[1] = a*a;
    out[2] = a*a*a;

    return out;
}


int main(){

    double *x = multiple_outputs(3);

     printf("%f\t%f\t%f\t",x[0],x[1],x[2]);

     free(x);
     return 0;

}



