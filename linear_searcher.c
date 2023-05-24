#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAX 100



int search(int arr[], int N, int x)
{
	int i;
	for (i = 0; i < N; i++){

        if (arr[i] == x)
			return i;
    }
		
	return -1;
}


int main()
{
	int arr[MAX];
    int i;
    int N;
    int x;
    int *p1;


    printf("\nEnter the size of array\n");
    scanf("%d",&N);
    p1 = arr;

    for(i=0;i<N;i++){
        printf("\n Enter the %d. member of this array \n",i+1);
        scanf("%d",p1);
        p1++;
    }

    printf("\n Enter a number to search in array\n");
    scanf("%d",&x);

    if (search(arr,N,x) == -1){
        printf("\n %d is not in this array\n",x);
    }

    else{
        printf("\n %d in this array\n",x);
    }


	
	return 0;
}
