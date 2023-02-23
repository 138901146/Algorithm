#include<stdio.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		int sum=0, min=100, temp;

		for(int i=0;i<7;i++)
		{
			scanf("%d", &temp);

			if(temp%2==0)
			{
				sum+=temp;
				min=temp<min?temp:min;
			}
		}

		printf("%d %d\n", sum, min);
	}

	return 0;
}