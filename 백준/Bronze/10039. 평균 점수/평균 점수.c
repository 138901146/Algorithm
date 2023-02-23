#include<stdio.h>

int main(void)
{
	int average=0;

	for(int i=0;i<5;i++)
	{
		int score;

		scanf("%d", &score);
		score/=5;
		score=score<8?8:score;

		average+=score;
	}

	printf("%d\n", average);

	return 0;
}