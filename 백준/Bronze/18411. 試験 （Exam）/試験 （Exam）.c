#include<stdio.h>

int main(void)
{
	int score, sum=0, min=100;

	for(int i=0;i<3;++i)
	{
		scanf("%d", &score);
		sum+=score;
		min=score<min?score:min;
	}

	printf("%d", sum-min);
	return 0;
}