#include<stdio.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		int sum=0, card[16];

		for(int i=0;i<16;i++)
		{
			scanf("%1d", &card[i]);
			sum+=i%2==1?card[i]:card[i]*2>9?2*card[i]/10+2*card[i]%10:2*card[i];
		}

		printf("%c\n", sum%10==0?'T':'F');
	}

	return 0;
}