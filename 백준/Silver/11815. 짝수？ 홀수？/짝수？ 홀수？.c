#include<stdio.h>
#include<math.h>

int main(void)
{
	int N;
	long long X, root;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%lld", &X);
		root=(long long)sqrt((double)X);
		printf("%d ", root*root==X);
	}

	return 0;
}