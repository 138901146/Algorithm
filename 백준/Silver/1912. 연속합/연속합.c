#include<stdio.h>
#include<stdlib.h>

int maximum_partial_sum(int *arr,int size)
{
	int max=arr[0], sum=0;

	for(int i=0;i<size;i++)
	{
		sum=arr[i]+sum>arr[i]?arr[i]+sum:arr[i];
		max=max>=sum?max:sum;
	}

	return max;
}

int main(void)
{
	int size, *arr=NULL;

	scanf("%d", &size);
	arr=(int *)malloc(size*sizeof(int));

	for(int i=0;i<size;i++)
		scanf("%d", &arr[i]);

	printf("%d\n", maximum_partial_sum(arr,size));

	free(arr);
	return 0;
}