#include<stdio.h>

int main(void)
{
	int N, count=0;

	scanf("%d", &N);

	for(int n=2023;n<=N;++n)
	{
		int temp=n, done=0;

		while(temp)
		{
			switch(done)
			{
				case 0:
					done+=temp%10==3;
					break;
				case 1:
					done+=temp%10==2;
					break;
				case 2:
					done+=temp%10==0;
					break;
				case 3:
					done+=temp%10==2;
					break;
			}

			temp/=10;
		}

		count+=done==4;
	}

	printf("%d", count);
	return 0;
}