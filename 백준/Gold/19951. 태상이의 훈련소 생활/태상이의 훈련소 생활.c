#include<stdio.h>

int main(void)
{
	int N, M, a, b, k, H[100002]={0}, soil[100002]={0};

	scanf("%d%d", &N, &M);

	for(int i=1;i<=N;++i)
		scanf("%d", &H[i]);

	while(M--)
	{
		scanf("%d%d%d", &a, &b, &k);
		soil[a]+=k;
		soil[b+1]-=k;
	}

	for(int i=1;i<=N;++i)
	{
		soil[i]+=soil[i-1];
		printf("%d ", H[i]+soil[i]);
	}

	return 0;
}