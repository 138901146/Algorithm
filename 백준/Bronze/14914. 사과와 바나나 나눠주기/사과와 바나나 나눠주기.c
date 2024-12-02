#include<stdio.h>

int main(void)
{
	int a, b;

	scanf("%d%d", &a, &b);

	for(int i=1;i<1001;++i)
		if(i<=a && i<=b && a%i==0 && b%i==0)
			printf("%d %d %d\n", i, a/i, b/i);

	return 0;
}