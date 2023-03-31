#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	N=N%4==0?N/4:N/4+1;

	for(int n=0;n<N;n++)
		printf("long ");
	printf("int\n");

	return 0;
}