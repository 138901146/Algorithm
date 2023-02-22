#include<stdio.h>

int main(void)
{
	int N, F;

	scanf("%d", &N);
	scanf("%d", &F);

	for(int i=0;i<100;i++)
		if((N-N%100+i)%F==0)
		{
			printf("%02d\n", i);
			break;
		}

	return 0;
}