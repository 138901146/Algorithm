#include<stdio.h>

int main(void)
{
	int N, count=0;

	scanf("%d", &N);

	for(int i=1;i*3<=N;i++)
		for(int j=i;i+2*j<=N;j++)
			count+=2*(i+j)>N;

	printf("%d\n", count);
	return 0;
}