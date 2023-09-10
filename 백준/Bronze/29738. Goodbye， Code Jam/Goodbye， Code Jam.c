#include<stdio.h>

int main(void)
{
	int T, N;

	scanf("%d", &T);

	for(int t=1;t<=T;++t)
	{
		scanf("%d", &N);

		printf("Case #%d: ", t);
		if(N<26)
			printf("World Finals\n");
		else if(N<1001)
			printf("Round 3\n");
		else if(N<4501)
			printf("Round 2\n");
		else
			printf("Round 1\n");
	}

	return 0;
}