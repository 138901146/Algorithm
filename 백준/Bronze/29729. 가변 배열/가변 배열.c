#include<stdio.h>

int main(void)
{
	int N, S, U, M;

	scanf("%d%d%d", &S, &M, &N);

	M+=N;
	U=0;

	while(M--)
	{
		scanf("%d", &N);

		if(N)
		{
			++U;
			if(S<U)
				S<<=1;
		}
		else
			--U;
	}

	printf("%d", S);
	return 0;
}