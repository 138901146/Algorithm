#include<stdio.h>

int main(void)
{
	int N, count=0, vote;

	scanf("%d", &N);

	for(int i=0;i<N;i++)
	{
		scanf("%d", &vote);

		count+=vote==0?-1:1;
	}

	printf("%s\n", count>0?"Junhee is cute!":"Junhee is not cute!");

	return 0;
}