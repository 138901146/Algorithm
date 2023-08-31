#include<stdio.h>

int main(void)
{
	int N, cage[3]={1,0,0}, until[3]={3,1,1};

	scanf("%d", &N);

	for(int n=1;n<N;n++)
	{
		cage[n%3]=cage[(n+2)%3]+until[(n+1)%3];
		until[n%3]=until[(n+2)%3]+(cage[n%3]<<1);

		cage[n%3]%=9901;
		until[n%3]%=9901;
	}

	printf("%d", until[(N-1)%3]);
	return 0;
}