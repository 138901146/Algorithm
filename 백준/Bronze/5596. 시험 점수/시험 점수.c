#include<stdio.h>

int main(void)
{
	int score, S=0, T=0;

	for(int i=0;i<4;i++)
	{
		scanf("%d", &score);
		S+=score;
	}
	for(int i=0;i<4;i++)
	{
		scanf("%d", &score);
		T+=score;
	}

	printf("%d\n", T>S?T:S);
	return 0;
}