#include<stdio.h>

int main(void)
{
	int count, order[100], number;

	scanf("%d", &count);

	for(int i=0;i<count;++i)
	{
		scanf("%d", &number);

		for(int j=0;j<number;++j)
			order[i-j]=order[i-j-1];
		order[i-number]=i+1;
	}

	for(int i=0;i<count;++i)
		printf("%d ", order[i]);
	return 0;
}