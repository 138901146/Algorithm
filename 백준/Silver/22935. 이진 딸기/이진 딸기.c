#include<stdio.h>

int main(void)
{
	int T, N;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &N);

		--N;
		N%=28;
		if(N<15)
			++N;
		else
			N=29-N;

		for(int i=3;0<=i;--i)
			printf("%s", 1<<i&N?"딸기":"V");
		printf("\n");
	}

	return 0;
}