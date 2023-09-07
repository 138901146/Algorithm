#include<stdio.h>

int main(void)
{
	int N, M, i, j, k, ball[101]={0, };

	scanf("%d%d", &N, &M);

	while(M--)
	{
		scanf("%d%d%d", &i, &j, &k);

		while(i<=j)
			ball[j--]=k;
	}

	for(int n=1;n<=N;++n)
		printf("%d ", ball[n]);

	return 0;
}