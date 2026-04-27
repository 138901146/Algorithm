#include<stdio.h>

int is_prime(int x)
{
	if(x<2)
		return 0;
	else if(x==2)
		return 1;
	else if(!(x&1))
		return 0;
	for(int i=3;i*i<=x;i+=2)
		if(!(x%i))
			return 0;
	return 1;
}

int main(void)
{
	int N, A[1000], one=0;

	scanf("%d", &N);

	for(int i=0;i<N;++i)
	{
		scanf("%d", &A[i]);
		if(A[i]==1)
		{
			one=1;
			--N;
			--i;
		}
	}

	if(1<N)
		printf("YES\n2\n%d %d", A[0], A[1]);
	else if(is_prime(A[0]))
		printf("NO");
	else
		printf("YES\n2\n1 %d", A[0]);
	return 0;
}