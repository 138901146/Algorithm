#include<stdio.h>

int main(void)
{
	int n, fibonacci[46]={0,1,1};

	scanf("%d", &n);

	for(int i=3;i<=n;i++)
		fibonacci[i]=fibonacci[i-1]+fibonacci[i-2];

	printf("%d\n", fibonacci[n]);

	return 0;
}