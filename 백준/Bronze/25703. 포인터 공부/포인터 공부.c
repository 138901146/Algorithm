#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	printf("int a;\nint *ptr = &a;");
	if(1<N)
		printf("\nint **ptr2 = &ptr;");
	for(int n=3;n<=N;++n)
	{
		printf("\nint ");
		for(int i=0;i<n;++i)
			printf("*");
		printf("ptr%d = &ptr%d;", n, n-1);
	}

	return 0;
}