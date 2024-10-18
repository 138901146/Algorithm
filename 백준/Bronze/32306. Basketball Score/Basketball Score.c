#include<stdio.h>

int main(void)
{
	int score[2]={0}, shoot[2][3];

	for(int i=0;i<2;++i)
		for(int j=0;j<3;++j)
			scanf("%d", &shoot[i][j]);

	for(int i=0;i<2;++i)
		for(int j=0;j<3;++j)
			score[i]+=(j+1)*shoot[i][j];

	printf("%d", score[0]<score[1]?2:score[1]<score[0]?1:0);
	return 0;
}