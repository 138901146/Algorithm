#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int compare(const void *x,const void *y)
{
    return *(int *)x>*(int *)y?1:*(int *)x==*(int *)y?0:-1;
}

int main(void)
{
    int N, M, *A=NULL;

    scanf("%d", &N);
    A=(int *)malloc(N*sizeof(int));

    for(int i=0;i<N;i++)
        scanf("%d", &A[i]);

    qsort((void *)A,(size_t)N,sizeof(int),compare);

    scanf("%d", &M);

    for(int i=0;i<M;i++)
    {
        int number;
        bool found=false;

        scanf("%d", &number);

        if(number<=A[N/2])
        {
            for(int j=0;A[j]<=number;j++)
                if(A[j]==number)
                {
                    found=true;
                    break;
                }
        }
        else
            for(int j=N-1;A[j]>=number;j--)
                if(A[j]==number)
                {
                    found=true;
                    break;
                }

        printf("%d\n", found);
    }

    free(A);
    return 0;
}