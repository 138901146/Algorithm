#include<stdio.h>

int main(void)
{
	int k, w, m;

	scanf("%d%d%d", &k, &w, &m);

	w-=k;

	printf("%d", w%m?w/m+1:w/m);
	return 0;
}