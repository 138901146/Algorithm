#include<stdio.h>

int main(void)
{
	int T, X, N, K, A;

	scanf("%d%d", &T, &X);
	scanf("%d", &N);

	while(N--)
	{
		int attendable=0;

		scanf("%d", &K);

		while(K--)
		{
			scanf("%d", &A);

			if(A==X)
				attendable=1;
		}

		if(!attendable)
		{
			printf("NO");
			return 0;
		}
	}

	printf("YES");
	return 0;
}