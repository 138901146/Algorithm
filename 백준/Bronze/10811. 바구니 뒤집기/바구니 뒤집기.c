#include<stdio.h>

int main(void)
{
	int N, M, basket[101], temp[101], i, j;

	scanf("%d%d", &N, &M);

	for(int n=1;n<=N;++n)
		basket[n]=n;

	while(M--)
	{
		scanf("%d%d", &i, &j);

		for(int x=i, y=j;x<=j;++x, --y)
			temp[x]=basket[y];

		for(int x=i;x<=j;++x)
			basket[x]=temp[x];
	}

	for(int n=1;n<=N;++n)
		printf("%d ", basket[n]);
	return 0;
}