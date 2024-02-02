#include<stdio.h>

int prefix_sum[200001][26]={0}, q, l, r;
char S[200001]={'\0'}, alpha;

int main(void)
{
	scanf("%s", S);

	for(int i=0;S[i];++i)
	{
		for(int j=0;j<26;++j)
			prefix_sum[i+1][j]=prefix_sum[i][j];
		++prefix_sum[i+1][S[i]-97];
	}

	scanf("%d", &q);
	while(q--)
	{
		getchar();
		scanf("%c%d%d", &alpha, &l, &r);
		alpha-=97;
		printf("%d\n", prefix_sum[r+1][alpha]-prefix_sum[l][alpha]);
	}

	return 0;
}