#include<stdio.h>

int main(void)
{
	int sleep, awake;

	scanf("%d", &sleep);
	scanf("%d", &awake);

	if(3<sleep)
		sleep-=24;

	printf("%d", awake-sleep);
	return 0;
}