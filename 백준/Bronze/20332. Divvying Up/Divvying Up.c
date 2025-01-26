#include<stdio.h>

int main(void)
{
	int n, w, total=0;

	scanf("%d", &n);

	while(n--)
	{
		scanf("%d", &w);
		total+=w;
	}

	printf("%s", total%3?"no":"yes");
	return 0;
}