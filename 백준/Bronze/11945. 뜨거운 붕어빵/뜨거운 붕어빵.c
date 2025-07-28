#include<stdio.h>

int main(void)
{
	int N, M, shape[10];

	scanf("%d%d", &N, &M);

	while(N--)
	{
		for(int m=0;m<M;++m)
			scanf("%1d", &shape[m]);
		for(int m=M-1;0<=m;--m)
			printf("%d", shape[m]);
		printf("\n");
	}

	return 0;
}