#include<stdio.h>

int main(void)
{
	int S, Ma, F, Mb;

	scanf("%d", &S);
	scanf("%d%d%d", &Ma, &F, &Mb);

	printf("%s", S<241 || S<=Ma+F+Mb?"high speed rail":"flight");
	return 0;
}