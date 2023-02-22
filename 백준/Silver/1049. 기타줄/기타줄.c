#include<stdio.h>

int main(void)
{
	int N, M, six, one, min6=60000, min1=10000;

	scanf("%d %d", &N, &M);

	for(int m=0;m<M;m++)
	{
		scanf("%d %d", &six, &one);

		min1=min1<one?min1:one;
		min6=6*one<min6?6*one:min6;
		min6=six<min6?six:min6;
	}

	printf("%d\n", min6*(N/6)+(min1*(N%6)<min6?min1*(N%6):min6));
	return 0;
}