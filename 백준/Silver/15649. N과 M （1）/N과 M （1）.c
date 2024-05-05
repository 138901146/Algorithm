#include<stdio.h>

int N, M, arr[8];

void N_M(int current,int flag)
{
	if(current==M)
	{
		for(int i=0;i<M;++i)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for(int i=1;i<=N;++i)
		if(!(flag&(1<<i)))
		{
			arr[current]=i;
			N_M(current+1,1<<i|flag);
		}
}

int main(void)
{
	scanf("%d%d", &N, &M);

	N_M(0,0);

	return 0;
}