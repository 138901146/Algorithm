#include<stdio.h>

int main(void)
{
	for(int i=0;i<3;i++)
	{
		int sum=0;

		for(int j=0;j<4;j++)
		{
			int yut;

			scanf("%d", &yut);

			sum+=yut;
		}

		printf("%c\n", sum==4?'E':3-sum+'A');
	}

	return 0;
}