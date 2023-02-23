#include<stdio.h>

int main(void)
{
	int score[5][4], max=0, max_index;

	for(int i=0;i<5;i++)
		for(int j=0;j<4;j++)
			scanf("%d", &score[i][j]);

	for(int i=0;i<5;i++)
	{
		int sum=0;

		for(int j=0;j<4;j++)
			sum+=score[i][j];

		max_index=max>sum?max_index:i+1;
		max=max>sum?max:sum;
	}

	printf("%d %d\n", max_index, max);

	return 0;
}