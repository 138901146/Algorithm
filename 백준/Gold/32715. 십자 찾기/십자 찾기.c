#include<stdio.h>
#include<stdbool.h>

bool paper[2501][2501]={0};
short up[2501][2501]={0}, down[2502][2501]={0}, left[2501][2501]={0}, right[2501][2502]={0};

int main(void)
{
	int N, M, K, count=0;

	scanf("%d%d", &N, &M);
	scanf("%d", &K);

	for(int r=1;r<=N;++r)
		for(int c=1;c<=M;++c)
		{
			scanf("%d", &paper[r][c]);

			up[r][c]=paper[r][c]?up[r-1][c]+1:0;
			left[r][c]=paper[r][c]?left[r][c-1]+1:0;
		}

	for(int r=N;r;--r)
		for(int c=M;c;--c)
		{
			down[r][c]=paper[r][c]?down[r+1][c]+1:0;
			right[r][c]=paper[r][c]?right[r][c+1]+1:0;

			count+=K<up[r][c]&&K<down[r][c]&&K<left[r][c]&&K<right[r][c];
		}

	printf("%d", count);
	return 0;
}