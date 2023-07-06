#include<stdio.h>

int arr[8], N, M;

void N_M(int x,int y)
{
	if(y==M)
	{
		for(int i=0;i<M;i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for(int i=x;i<=N;i++)
	{
		arr[y]=i;
		N_M(i,y+1);
	}
}

int main(void)
{
	scanf("%d%d", &N, &M);

	N_M(1,0);
	return 0;
}