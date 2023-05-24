#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct car
{
    char model[20];
    int year;
    int price;
    char color[20];
    
};

//structtaki değişkenler mainin dışında tanımlanan  struct içinde tanımlanmış olur.




int main(){



struct car car_a;//ikinci kısım değişkeni  ifade ediyor.
strcpy(car_a.color,"red");
strcpy(car_a.model,"BMW");
car_a.price=10000;
car_a.year=2020;

//structa değerler nokta ile ifade edilir.

printf("Car A 's model is %s\n",car_a.model);
printf("Car A 's year is %d\n",car_a.year);
printf("Car A 's price is %d\n",car_a.price);
printf("Car A 's color is %s\n",car_a.color);



return 0;


}