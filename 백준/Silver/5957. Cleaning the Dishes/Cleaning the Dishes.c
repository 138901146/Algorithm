#include<stdio.h>

int main(void)
{
	int N, stack[10000][3], top[3]={0};

	scanf("%d", &N);

	for(int i=N;i;--i)
		stack[top[0]++][0]=i;

	while(top[2]!=N)
	{
		int C, D;

		scanf("%d%d", &C, &D);

		while(D--)
			stack[top[C]++][C]=stack[--top[C-1]][C-1];
	}

	while(top[2])
		printf("%d\n", stack[--top[2]][2]);
	return 0;
}