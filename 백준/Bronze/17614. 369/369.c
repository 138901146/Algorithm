#include<stdio.h>

int main(void)
{
	int N, count=0;

	scanf("%d", &N);

	for(int i=1;i<=N;++i)
	{
		int temp=i;

		while(temp)
		{
			switch(temp%10)
			{
				case 3:
				case 6:
				case 9:
					++count;
					break;
				default:
					break;
			}

			temp/=10;
		}
	}

	printf("%d", count);
	return 0;
}
