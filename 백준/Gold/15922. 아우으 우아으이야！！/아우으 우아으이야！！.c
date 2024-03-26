#include<stdio.h>

int main(void)
{
	int N, start, end=-1000000001, length=0, x, y;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d%d", &x, &y);

		if(end<x)
		{
			start=x;
			end=y;
			length+=y-x;
		}
		else if(end<y)
		{
			length+=y-end;
			end=y;
		}
	}

	printf("%d", length);
	return 0;
}