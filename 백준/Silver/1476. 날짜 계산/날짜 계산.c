#include<stdio.h>

int main(void)
{
	int E, S, M, year;

	scanf("%d %d %d", &E, &S, &M);

	for(year=1;(year-1)%15+1!=E||(year-1)%28+1!=S||(year-1)%19+1!=M;year++);

	printf("%d\n", year);
	return 0;
}