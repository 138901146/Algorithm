#include<stdio.h>

int main(void)
{
	int today[3], N, gifticon[3], count=0;

	scanf("%d-%d-%d", &today[0], &today[1], &today[2]);
	scanf("%d", &N);

	while(N--)
	{
		scanf("%d-%d-%d", &gifticon[0], &gifticon[1], &gifticon[2]);
		count+=today[0]<gifticon[0] || today[0]==gifticon[0]&&today[1]<gifticon[1] || today[0]==gifticon[0]&&today[1]==gifticon[1]&&today[2]<=gifticon[2];
	}

	printf("%d\n", count);
	return 0;
}