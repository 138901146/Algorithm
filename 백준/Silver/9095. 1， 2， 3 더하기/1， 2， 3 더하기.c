#include<stdio.h>

int sum[11]={0, };

int find_n(int n)
{
	if(n<3)
		return n;
	else if(n==3)
		return sum[3]=4;
	else if(sum[n])
		return sum[n];
	else
		return sum[n]=find_n(n-1)+find_n(n-2)+find_n(n-3);
}

int main(void)
{
	int T, n;

	scanf("%d", &T);
	for(int t=0;t<T;t++)
	{
		scanf("%d", &n);
		printf("%d\n", find_n(n));
	}

	return 0;
}