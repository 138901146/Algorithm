#include<stdio.h>

int main(void)
{
	int n, count=0;
	char c;

	scanf("%d", &n);
	getchar();

	while(n--)
	{
		c=getchar();
		count+=c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
	}

	printf("%d", count);
	return 0;
}