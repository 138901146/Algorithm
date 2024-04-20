#include<stdio.h>

int bright_sum[1001][1001]={0};

int main(void)
{
	int R, C, Q, r1, r2, c1, c2;

	scanf("%d%d%d", &R, &C, &Q);

	for(int r=1;r<=R;++r)
		for(int c=1;c<=C;++c)
		{
			scanf("%d", &bright_sum[r][c]);
			bright_sum[r][c]+=bright_sum[r-1][c]+bright_sum[r][c-1]-bright_sum[r-1][c-1];
		}

	while(Q--)
	{
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		printf("%d\n", (bright_sum[r2][c2]-bright_sum[r1-1][c2]-bright_sum[r2][c1-1]+bright_sum[r1-1][c1-1])/((r2-r1+1)*(c2-c1+1)));
	}

	return 0;
}