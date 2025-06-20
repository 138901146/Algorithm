#include<stdio.h>

int main(void)
{
	int T, N, M;

	scanf("%d", &T);

	while(T--)
	{
		int count=0;

		scanf("%d%d", &N, &M);

		count+=!N;
		for(int i=N;i<=M;++i)
		{
			int temp=i;

			while(temp)
			{
				count+=!(temp%10);
				temp/=10;
			}
		}

		printf("%d\n", count);
	}

	return 0;
}