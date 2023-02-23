#include<stdio.h>
#include<stdlib.h>

int abs(int X)
{
	return X<0?-X:X;
}

int main(void)
{
	int N, *num=NULL, lastdifference=1000000000;

	scanf("%d", &N);
	num=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;n++)
		scanf("%d", &num[n]);

	for(int i=1;i<10001;i++)
	{
		int difference=0;

		for(int n=0;n<N;n++)
			difference+=abs(i-num[n]);

		if(difference>=lastdifference)
		{
			printf("%d\n", i-1);
			break;
		}
		else
			lastdifference=difference;
	}

	free(num);
	return 0;
}