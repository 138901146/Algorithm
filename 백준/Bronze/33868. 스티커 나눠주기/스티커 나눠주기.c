#include<stdio.h>

int main(void)
{
	int N, T=0, B=5001, t, b;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d%d", &t, &b);
		T=t<T?T:t;
		B=b<B?b:B;
	}

	printf("%d", (T*B%7)+1);
	return 0;
}