#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max2(int x,int y)
{
   return x>y?x:y;
}

int max3(int x,int y,int z)
{
   return x>=y&&x>=z?x:y>=x&&y>=z?y:z;
}

int main(void)
{
   char A[1001]={'\0', }, B[1001]={'\0', };
   int **LCS=NULL, a, b;

   scanf("%s%s", A, B);
   a=strlen(A);
   b=strlen(B);

   LCS=(int **)malloc((a+1)*sizeof(int *));
   for(int i=0;i<=a;i++)
      LCS[i]=(int *)calloc(b+1,sizeof(int));

   for(int i=1;i<=a;i++)
      for(int j=1;j<=b;j++)
         if(A[i-1]!=B[j-1])
            LCS[i][j]=max2(LCS[i-1][j],LCS[i][j-1]);
         else
            LCS[i][j]=max3(LCS[i-1][j],LCS[i][j-1],LCS[i-1][j-1]+1);

   printf("%d\n", LCS[a][b]);
   for(int i=0;i<=a;i++)
      free(LCS[i]);
   free(LCS);
   return 0;
}