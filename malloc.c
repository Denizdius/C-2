#include <stdio.h>
#include <stdlib.h>

int main()
{

  int *p1;

  int n;
  
  int i;
  printf("Enter a value\n");
  scanf("%d",&n);

  p1=(int*)malloc(n*sizeof(int));
  // malloc mememoryden bir yer ayırmanı sağlar

  if(p1==NULL)
  {
      printf("ERORR\n");
  }

  else
  {
      for(i=0;i<n;i++)
      {
          p1[i]=i+1;
      }

      printf("My integers\n");
      for(i=0;i<n;i++)
      {
          printf("%d, ",p1[i]);
      }

      free(p1);

  }
    return 0;
}