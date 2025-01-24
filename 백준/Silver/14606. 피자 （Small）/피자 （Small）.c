#include<stdio.h>

int get_fun(int x)
{
	if(x<2)
		return 0;

	return (x>>1)*(x-(x>>1))+get_fun(x>>1)+get_fun(x-(x>>1));
}

int main(void)
{
	int N;

	scanf("%d", &N);

	printf("%d", get_fun(N));
	return 0;
}