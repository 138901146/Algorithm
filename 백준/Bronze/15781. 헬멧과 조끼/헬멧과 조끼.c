#include<stdio.h>

int main(void)
{
	int N, M, a, max_a=0, h, max_h=0;;

	scanf("%d %d", &N, &M);

	for(int n=0;n<N;n++)
	{
		scanf("%d", &h);
		max_h=h>max_h?h:max_h;
	}
	for(int m=0;m<M;m++)
	{
		scanf("%d", &a);
		max_a=a>max_a?a:max_a;
	}

	printf("%d\n", max_h+max_a);
	return 0;
}