#include<stdio.h>

int main(void)
{
	int N, M, basket[101], i, j, k, temp[101];

	scanf("%d%d", &N, &M);

	for(i=1;i<=N;++i)
		basket[i]=i;

	while(M--)
	{
		scanf("%d%d%d", &i, &j, &k);

		for(int x=k;x<=j;++x)
			temp[x-k+i]=basket[x];
		for(int x=k-1;i<=x;--x)
			temp[x+j-k+1]=basket[x];

		for(int x=i;x<=j;++x)
			basket[x]=temp[x];
	}

	for(i=1;i<=N;++i)
		printf("%d ", basket[i]);
	return 0;
}