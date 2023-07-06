#include<stdio.h>

int arr[8], N, M;

void N_M(int x)
{
	if(x==M)
	{
		for(int i=0;i<M;i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for(int i=1;i<=N;i++)
	{
		arr[x]=i;
		N_M(x+1);
	}
}

int main(void)
{
	scanf("%d%d", &N, &M);

	N_M(0);
	return 0;
}