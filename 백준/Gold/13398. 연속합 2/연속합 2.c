#include<stdio.h>

int main(void)
{
	int n, number, sum[2]={0}, max[2];

	scanf("%d", &n);

	scanf("%d", &number);
	max[0]=max[1]=sum[0]=number;

	while(--n)
	{
		scanf("%d", &number);

		sum[1]=sum[1]+number<sum[0]?sum[0]:sum[1]+number;
		sum[0]=number<number+sum[0]?number+sum[0]:number;

		max[0]=sum[0]<max[0]?max[0]:sum[0];
		max[1]=sum[1]<max[1]?max[1]:sum[1];
	}

	printf("%d", max[0]<max[1]?max[1]:max[0]);
	return 0;
}