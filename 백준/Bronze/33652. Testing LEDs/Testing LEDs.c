#include<stdio.h>

#define INF 3000000000

int main(void)
{
	int N, M, O;
	long long min=INF;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d%d", &M, &O);

		if(!O)
			min=M<min?M:min;
	}

	printf("%lld", min==INF?-1:min);
	return 0;
}