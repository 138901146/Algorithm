#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int count=1, max=1, N, *arr=NULL;

	scanf("%d", &N);
	arr=(int *)malloc(N*sizeof(int));
	for(int i=0;i<N;i++)
		scanf("%d", &arr[i]);

	for(int i=1;i<N;i++)
		if(arr[i]>=arr[i-1])
		{
			count++;
			max=max>count?max:count;
		}
		else
			count=1;
	count=1;
	for(int i=1;i<N;i++)
		if(arr[i]<=arr[i-1])
		{
			count++;
			max=max>count?max:count;
		}
		else
			count=1;

	printf("%d\n", max);
	free(arr);
	return 0;
}