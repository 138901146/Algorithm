#include<stdio.h>

int main(void)
{
	int N, number=665;

	scanf("%d", &N);

	while(N)
	{
		int temp=++number, max=0, continuous=0;

		while(temp)
		{
			if(temp%10==6)
				max=++continuous>max?continuous:max;
			else
				continuous=0;

			temp/=10;
		}

		if(max>2)
			--N;
	}

	printf("%d", number);
	return 0;
}