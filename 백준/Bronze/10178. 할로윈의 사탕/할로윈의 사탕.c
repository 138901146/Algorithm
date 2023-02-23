#include<stdio.h>

int main(void)
{
	int T, candy, children;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		scanf("%d %d", &candy, &children);
		printf("You get %d piece(s) and your dad gets %d piece(s).\n", candy/children, candy%children);
	}

	return 0;
}