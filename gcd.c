#include <stdio.h> 
#include<stdlib.h>
#include<math.h>




int gcd(int a,int b){

    while(a != b){
        if(a > b){
            a = a - b;
        }

        else{
            b = b-a;
        }
    }
    return a;
}

int main(){

    int n1;
    int n2;
    int answer;


    printf("\n Enter two numbers to find gcd, first enter one number \n");
    scanf("%d",&n1);

    printf("\n Enter two numbers to find gcd,  enter the other  number \n");
    scanf("%d",&n2);

    answer = gcd(n1,n2);
    printf("\nGcd is %d\n",answer);
 


}