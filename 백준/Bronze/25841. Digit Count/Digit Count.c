#include<stdio.h>

int main(void)
{
	int start, end, digit, count=0;

	scanf("%d%d%d", &start, &end, &digit);

	for(int num=start;num<=end;++num)
	{
		int temp=num;

		while(temp)
		{
			count+=temp%10==digit;
			temp/=10;
		}
	}

	printf("%d", count);
	return 0;
}