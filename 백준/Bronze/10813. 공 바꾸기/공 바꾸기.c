#include<stdio.h>

int main(void)
{
	int N, M, i, j, basket[101];

	scanf("%d%d", &N, &M);

	for(int n=1;n<=N;++n)
		basket[n]=n;

	while(M--)
	{
		scanf("%d%d", &i, &j);

		int temp=basket[i];
		basket[i]=basket[j];
		basket[j]=temp;
	}

	for(int n=1;n<=N;++n)
		printf("%d ", basket[n]);
	return 0;
}