#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	for(int n=0;n<N;n++)
	{
		int shape[2][5]={0, }, play;
		char winner='D';

		for(int i=0;i<2;i++)
		{
			scanf("%d", &shape[i][0]);
			for(int j=0;j<shape[i][0];j++)
			{
				scanf("%d", &play);
				shape[i][play]++;
			}
		}

		for(int i=4;i>0;i--)
			if(shape[0][i]>shape[1][i])
			{
				winner='A';
				break;
			}
			else if(shape[0][i]<shape[1][i])
			{
				winner='B';
				break;
			}

		printf("%c\n", winner);
	}

	return 0;
}