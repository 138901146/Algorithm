#include<stdio.h>
#include<malloc.h>
#include<string.h>

int main(void)
{
    int N, *C=NULL, price, count=0;
    char D[16]={'\0'};

    scanf("%d", &N);
    C=(int *)malloc(N*sizeof(int));

    for(int n=0;n<N;++n)
    {
        getchar();
        scanf("%s%d", D, &C[n]);

        if(strcmp(D,"jinju")==0)
            price=C[n];
    }

    for(int n=0;n<N;++n)
        count+=C[n]>price;

    printf("%d\n%d", price, count);
    free(C);
    return 0;
}