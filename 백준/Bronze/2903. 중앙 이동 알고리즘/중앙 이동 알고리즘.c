#include<stdio.h>

int main(void)
{
	int N, power=1;

	scanf("%d", &N);

	for(int n=0;n<N;n++)
		power*=2;
	power++;

	printf("%d\n", power*power);
	return 0;
}