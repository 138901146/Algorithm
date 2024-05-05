#include<stdio.h>

int N, M, arr[7];

void N_M(int current)
{
	if(current==M)
	{
		for(int i=0;i<M;++i)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for(int i=1;i<=N;++i)
	{
		arr[current]=i;
		N_M(current+1);
	}
}

int main(void)
{
	scanf("%d%d", &N, &M);

	N_M(0);

	return 0;
}