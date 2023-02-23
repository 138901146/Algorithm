#include<stdio.h>

int main(void)
{
	int N, k, cal=1;

	scanf("%d", &N);
	scanf("%d", &k);

	for(int i=0;i<k;i++)
		cal=10*cal+1;

	printf("%d\n", N*cal);
	return 0;
}