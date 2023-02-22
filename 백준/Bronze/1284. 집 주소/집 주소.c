#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);
	while(N!=0)
	{
		int temp=N, length=1;

		while(temp>0)
		{
			length+=temp%10==0?5:temp%10==1?3:4;
			temp/=10;
		}
			printf("%d\n", length);
			scanf("%d", &N);
	}

	return 0;
}