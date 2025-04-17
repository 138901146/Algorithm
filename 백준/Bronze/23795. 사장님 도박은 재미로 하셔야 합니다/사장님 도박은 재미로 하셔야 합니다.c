#include<stdio.h>

int main(void)
{
	int N=0, sum=0;

	do
	{
		sum+=N;
		scanf("%d", &N);
	}
	while(N!=-1);

	printf("%d", sum);
	return 0;
}