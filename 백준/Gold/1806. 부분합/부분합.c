#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, S, min=100000, *arr=NULL, left=0, right=0;

	scanf("%d%d", &N, &S);
	arr=(int *)calloc(N+1,sizeof(int));

	for(int n=1;n<=N;n++)
	{
		scanf("%d", &arr[n]);
		arr[n]+=arr[n-1];
	}

	if(arr[N]<S)
	{
		printf("0\n");
		return 0;
	}

	while(right<N && arr[++right]<S);
	while(left<right && arr[right]-arr[++left]>=S);
	min=right-left<min?right-left:min;
	while(++right<=N)
	{
		while(left<right && arr[right]-arr[++left]>=S);
		min=right-left<min?right-left:min;
	}

	printf("%d\n", min+1);
	free(arr);
	return 0;
}