#include<stdio.h>

int main(void)
{
	int N, count=0;

	scanf("%d", &N);

	for(int B=1;B<=500;B++)
		for(int A=B;A*A-B*B<=N;A++)
			count+=A*A-B*B==N;

	printf("%d\n", count);
	return 0;
}