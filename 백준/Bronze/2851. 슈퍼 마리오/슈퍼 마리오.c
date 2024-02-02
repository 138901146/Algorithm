#include<stdio.h>

int main(void)
{
	int mushroom, sum=0;

	for(int i=0;i<10;++i)
	{
		scanf("%d", &mushroom);

		if(100<=sum+mushroom)
		{
			sum=sum+mushroom-100<=100-sum?sum+mushroom:sum;
			break;
		}

		sum+=mushroom;
	}

	printf("%d", sum);
	return 0;
}