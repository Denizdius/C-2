#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct name {

    char name[20];
    int id_number;
    int year_of_birth;


};

void print_student(struct name student[],int n){

    int i;

    for(i=0; i<n; i++){
        printf("%s \t %d \t %d\n ", student[i].name, student[i].id_number, student[i].year_of_birth);

}


}



int main(){

    struct name student[4] = {{" Deniz", 290206063, 2003}, {"Beril", 280206002, 2002}, {"Enes", 280206035, 2002},{"Dora", 280206042, 2002}};

  

    print_student(student , 4);

    return 0;


}