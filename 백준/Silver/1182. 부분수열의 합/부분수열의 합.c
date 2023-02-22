#include<stdio.h>
#include<stdlib.h>

int backtrack(int *arr,int current,int N,int S,int sum,int count)
{
	if(current==N)
		return sum==S&&count>0;
	return backtrack(arr,current+1,N,S,sum+arr[current],count+1)+backtrack(arr,current+1,N,S,sum,count);
}

int main(void)
{
	int N, *arr=NULL, S;

	scanf("%d%d", &N, &S);
	arr=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;i++)
		scanf("%d", &arr[i]);

	printf("%d\n", backtrack(arr,0,N,S,0,0));
	free(arr);
	return 0;
}