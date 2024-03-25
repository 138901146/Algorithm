#include<stdio.h>

int main(void)
{
	int score, min[2]={100,100}, sum=0;

	for(int i=0;i<4;++i)
	{
		scanf("%d", &score);
		sum+=score;
		min[0]=score<min[0]?score:min[0];
	}

	for(int i=0;i<2;++i)
	{
		scanf("%d", &score);
		sum+=score;
		min[1]=score<min[1]?score:min[1];
	}

	printf("%d", sum-min[0]-min[1]);
	return 0;
}