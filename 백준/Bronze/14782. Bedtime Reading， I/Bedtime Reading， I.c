#include<stdio.h>

int main(void)
{
	int I, sum=0;

	scanf("%d", &I);

	for(int i=1;i<=I/2;i++)
		if(I%i==0)
			sum+=i;
	sum+=I;

	printf("%d\n", sum);
	return 0;
}