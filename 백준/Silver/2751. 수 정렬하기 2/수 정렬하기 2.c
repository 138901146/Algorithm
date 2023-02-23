#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?1:*(int *)x==*(int *)y?0:-1;
}

int main(void)
{
	int N, *arr=NULL;

	scanf("%d", &N);
	arr=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;i++)
		scanf("%d", &arr[i]);

	qsort((void *)arr,(size_t)N,sizeof(int),compare);

	for(int i=0;i<N;i++)
		printf("%d\n", arr[i]);

	free(arr);
	return 0;
}