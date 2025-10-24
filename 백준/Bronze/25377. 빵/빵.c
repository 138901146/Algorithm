#include<stdio.h>

#define INF 9999

int main(void)
{
	int N, A, B, min=INF;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d%d", &A, &B);
		if(A<=B)
			min=B<min?B:min;
	}

	printf("%d", min==INF?-1:min);
	return 0;
}