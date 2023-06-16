#include<stdio.h>

int main(void)
{
	int N, pillar[1002]={0, }, prefix[1002]={0, }, suffix[1002]={0, }, sum=0, L, H, left=1001, right=0;

	scanf("%d", &N);

	for(int i=0;i<N;i++)
	{
		scanf("%d%d", &L, &H);
		pillar[L]=H;
		left=L<left?L:left;
		right=L>right?L:right;
	}

	for(int i=left;i<=right;i++)
		prefix[i]=pillar[i]>prefix[i-1]?pillar[i]:prefix[i-1];
	for(int i=right;i>=left;i--)
		suffix[i]=pillar[i]>suffix[i+1]?pillar[i]:suffix[i+1];

	for(int i=left;i<=right;i++)
		sum+=prefix[i]<suffix[i]?prefix[i]:suffix[i];

	printf("%d\n", sum);
	return 0;
}