#include<stdio.h>

int main(void)
{
	int N, combination=1;

	scanf("%d", &N);

	for(int i=0;i<5;++i)
	{
		combination*=N-i;
		combination/=i+1;
	}

	printf("%d", combination);
	return 0;
}