#include<stdio.h>

int main(void)
{
	float M;

	scanf("%f", &M);

	if(M<31)
		printf("%.1f", M/2);
	else
		printf("%.1f", 15+((M-30)*3/2));

	return 0;
}