#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


int main(){

char word[100];
char *p1;
char *p2;
int i;

int m;

printf("\n Enter a word\n");
gets(word);

m = strlen(word);


for(p2 = word,i =0; i<m;p2++,i++){

}

p2--;

for(p1 = word ; p1<p2;p1 ++,p2--){

    if ( *p1 != *p2){
        printf("\nThis word is not a palendrom word  \n");
        return 0;
    
    }

    else 
    continue;
    
}

printf("\n This word is palendrom word \n");

return 0;
}


