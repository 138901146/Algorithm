#include<stdio.h>

int main(void)
{
	int n, count=0;

	scanf("%d", &n);

	for(int i=1;i<=n;i++)
		for(int j=1;j<=i && i*j<=n;j++)
			count+=i*j<=n;

	printf("%d\n", count);
	return 0;
}