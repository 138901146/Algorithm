#include<stdio.h>

int main(void)
{
	int score[2][10]={0}, reverse=0;

	for(int i=0;i<2;++i)
		for(int j=1;j<10;++j)
			scanf("%d", &score[i][j]);

	for(int i=1;i<10;++i)
	{
		score[0][i]+=score[0][i-1];
		score[1][i]+=score[1][i-1];

		if(score[1][i-1]<score[0][i])
			reverse=1;
	}

	printf("%s", reverse&(score[0][9]<score[1][9])?"Yes":"No");
	return 0;
}