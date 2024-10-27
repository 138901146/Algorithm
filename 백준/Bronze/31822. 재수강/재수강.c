#include<stdio.h>

int main(void)
{
	int N, count=0;
	char origin[11], compare[11];

	scanf("%s", origin);

	scanf("%d", &N);

	while(N--)
	{
		scanf("%s", compare);
		count+=origin[0]==compare[0]&&origin[1]==compare[1]&&origin[2]==compare[2]&&origin[3]==compare[3]&&origin[4]==compare[4];
	}

	printf("%d", count);
	return 0;
}