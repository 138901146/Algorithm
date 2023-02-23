#include<stdio.h>

int main(void)
{
	int total=0, score;

	for(int i=0;i<5;i++)
	{
		scanf("%d", &score);
		total+=score;
	}

	printf("%d\n", total);
	return 0;
}