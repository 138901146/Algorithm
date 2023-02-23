#include<stdio.h>

int main(void)
{
	int integer[201]={0, }, N, v;

	scanf("%d", &N);

	for(int n=0;n<N;n++)
	{
		scanf("%d", &v);
		integer[v+100]++;
	}

	scanf("%d", &v);
	printf("%d\n", integer[v+100]);
	return 0;
}